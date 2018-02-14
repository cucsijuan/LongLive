// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Opinion.generated.h"

UENUM()
enum class ERelationModifiers : uint8
{
	GIFT,
	FAVOUR,
	COMPETITION,
};

struct SOpinion
{
	ERelationModifiers RelationMod;
	uint32 OpinionMod; //How Much the opinion grows or decreases
	FString Desc; //Desc of the opinion modifier
	uint32 Time; // date stamp when it should finish
};

/**
 * 
 */
UCLASS()
class LONGLIVETHEKING_API UOpinion : public UObject
{
	GENERATED_BODY()
	
public:
	void SetOpinion(ERelationModifiers RelationModifier, uint32 amount = 0, uint32 time = 0);

private:
	uint32 TotalOpinion = 0;
	TArray<SOpinion> OpinionsArray;

};
