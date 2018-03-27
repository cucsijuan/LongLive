// Fill out your copyright notice in the Description page of Project Settings.

#include "People.h"
#include "Player/Opinion.h"
#include "Paths.h"
#include "FileHelper.h"


TMap<uint32, UOpinion *> OpinionMap;

UPeople::UPeople()
{
	LoadNames();
}

void UPeople::GenerateRelation(uint32 CharID)
{
	UOpinion * Temp = NewObject<UOpinion>(this);
	OpinionMap.Add(CharID, Temp);
}

FString UPeople::GetName()
{
	return Name;
}

FString UPeople::GetLastName()
{
	return LastName;
}

void UPeople::LoadNames()
{
	FString GameDir = FPaths::GameDir();
	FString CompleteFilePath = GameDir + "Content/Dynamic/Data/ASAXON_NAMES_M.txt";

	FString FileData = "";
	FFileHelper::LoadFileToString(FileData, *CompleteFilePath);

	UE_LOG(LogTemp, Log, TEXT("Saxon names File: \n %s"), *FileData);

	int32 lineCount = FileData.ParseIntoArray(SaxonNames,_T("\n"), true);

	for (FString line : SaxonNames)
	{
		UE_LOG(LogTemp, Log, TEXT("Saxon name: \n %s"), *line);
	}
}

void UPeople::SetPeopleData(FString Name, FString LastName, FString Lineage, FString Possesions)
{
	this->Name = Name;
	this->LastName = LastName;
	this->Lineage = Lineage;
	this->Possesions = Possesions;
	CharAttributes.Charisma = 5;
	CharAttributes.Constitution = 5;
	CharAttributes.Perception = 5;
	CharAttributes.Strength = 5;
}



