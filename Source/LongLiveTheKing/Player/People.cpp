// Fill out your copyright notice in the Description page of Project Settings.

#include "People.h"
#include "Player/Opinion.h"

TMap<uint32, UOpinion *> OpinionMap;

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



