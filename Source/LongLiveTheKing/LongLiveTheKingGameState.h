// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Engine/StreamableManager.h"
#include "LongLiveTheKingGameState.generated.h"

class UTexture2D;

USTRUCT()
struct FSCounty
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;  //Nombre
	UPROPERTY()
	class UPeople * Lord; //County Owner
	UPROPERTY()
	FString Duchy; //Duchy where it belongs
	UPROPERTY()
	FColor ColorID; //County ID
};
USTRUCT()
struct FSDuchy
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;  //Nombre
	UPROPERTY()
	class UPeople * Lord; //Duchy Owner
	UPROPERTY()
	TArray<FSCounty> Vassals; //Vassals of the duchy as pointer of FScounty
};


/**
 * 
 */
UCLASS()
class LONGLIVETHEKING_API ALongLiveTheKingGameState : public AGameStateBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	TMap<uint32,FSDuchy> Duchies;
	UPROPERTY()
	TMap<FColor,FSCounty> Counties; //TODO: en realidad queria guardar una referencia del county, como no se puede lo dejo por copia, hay que ver si es util mantener una lista de condados
	UPROPERTY()
	UTexture2D * CountyMap;

	//Finds a County by Name in the Duchies Array
	bool FindCountyByName(FString CountyName, int32 duchyID, FSCounty & OutCounty);

public:
	UFUNCTION(BlueprintCallable,category = "Setup")
	void LoadMapData();
	UFUNCTION(BlueprintCallable, category = "CountyMap Texture")
	//Gets the Pixel color of a given Percentage for the CountyMap texture
	FColor GetCoordColor(FVector2D CoordPercent, UTexture2D * Texture);
	UFUNCTION(BlueprintCallable, category = "CountyMap Texture")
	//Transforms a map location, to a percentage
	FVector2D MapUnitsToPercent(int mouseX, int mouseY, FVector2D MapBounds);
	UFUNCTION(BlueprintCallable, category = "CountyMap Texture")
	//Finds a County by color ID in the Counties Array
	FString FindCountyByColor(FColor Color);
};
