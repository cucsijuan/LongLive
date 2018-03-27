// Fill out your copyright notice in the Description page of Project Settings.

#include "LongLiveTheKingGameState.h"
#include "TextureResource.h"
#include "Engine/Texture2D.h"
#include "FileHelper.h"

bool ALongLiveTheKingGameState::FindCountyByName(FString CountyName, int32 duchyID, FSCounty & OutCounty)
{
	
	for (FSCounty county : Duchies[duchyID].Vassals)
	{
		if (county.Name.Equals(CountyName))
		{
			OutCounty = county;
			return true;
		}
	}

	return false;

}

void ALongLiveTheKingGameState::LoadMapData()
{	
	FString GameDir = FPaths::GameDir();
	FString CompleteFilePath = GameDir + "Content/Dynamic/Data/MAP_DATA.txt";

	FString FileData = "";
	FFileHelper::LoadFileToString(FileData, *CompleteFilePath);
	
	TArray<FString> TempData;
	int32 lineCount = FileData.ParseIntoArray(TempData, _T("\n"), true);

	for (FString line : TempData)
	{
		TArray<FString> TempLine;
		TArray<FString> TempColorLine;

		line.ParseIntoArray(TempLine, _T(";"));
		TempLine[4].ParseIntoArray(TempColorLine, _T(","));

		FSCounty TempCounty;
		FSDuchy TempDuchy;
		
		TempCounty.Name = TempLine[1];
		TempCounty.Lord = nullptr;
		TempCounty.Duchy = TempDuchy.Name = TempLine[2];
		TempCounty.ColorID = FColor(FCString::Atoi(*TempColorLine[0]), FCString::Atoi(*TempColorLine[1]), FCString::Atoi(*TempColorLine[2]));
		
		int DuchyID = FCString::Atoi(*TempLine[0]);

		if (Duchies.Num() == 0 || !Duchies.Contains(DuchyID))
		{
			TempDuchy.Name = TempLine[2];
			TempDuchy.Lord = nullptr;
			Duchies.Add(DuchyID, TempDuchy);
		}

		Duchies[DuchyID].Vassals.Add(TempCounty);
		
		if (TempCounty.ColorID != FColor(255, 255, 255))
		{
			FSCounty CountyFound;
			bool result = FindCountyByName(TempCounty.Name, DuchyID, CountyFound);
			if (result)
				Counties.Add(TempCounty.ColorID, CountyFound);
		}
		
		UE_LOG(LogTemp, Log, TEXT("Duchy and county Added: \n %s, %s"), *TempDuchy.Name, *TempCounty.Name);

	}
	
}

FColor ALongLiveTheKingGameState::GetCoordColor(FVector2D CoordPercent, UTexture2D * Texture)
{
	if (Texture == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No texture was found on ALongLiveTheKingGameState::GetCoordColor "));
		return FColor(255, 255, 255);
	}
	FTexture2DMipMap * MainMipMap = &Texture->PlatformData->Mips[0];
	FByteBulkData* RawImageData = &MainMipMap->BulkData;
	FColor* FormatedImageData = static_cast<FColor*>(RawImageData->Lock(LOCK_READ_ONLY));

	int TextureWidth = MainMipMap->SizeX, TextureHeight = MainMipMap->SizeY;
	int X, Y;

	X = (TextureWidth * CoordPercent.X) / 100;
	Y = (TextureHeight * CoordPercent.Y) / 100;

	FColor PixelColor;
	
	if (X >= 0 && X < TextureWidth && Y >= 0 && Y < TextureHeight)
	{
		PixelColor = FormatedImageData[Y * TextureWidth + X];
		RawImageData->Unlock();
		return PixelColor;
	}
	else
	{
		RawImageData->Unlock();
		return FColor(255, 255, 255);
	}

	
}

FVector2D ALongLiveTheKingGameState::MapUnitsToPercent(int mouseX, int mouseY, FVector2D MapBounds)
{
	int percX, percY;
	percX = (mouseX * 100) / MapBounds.X;
	percY = (mouseY * 100) / MapBounds.Y;

	return FVector2D(percX,percY);
}

FString ALongLiveTheKingGameState::FindCountyByColor(FColor Color)
{
	FSCounty * TempCounty = Counties.Find(Color);
	if (TempCounty == nullptr)
	{
		return FString("Nothing");
	}

	return TempCounty->Name;
}
