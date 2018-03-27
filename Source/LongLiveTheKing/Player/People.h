// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "People.generated.h"

USTRUCT()
struct FSCharAttributes
{
	GENERATED_BODY()

	UPROPERTY()
	uint32 Strength;  //Marcial
	UPROPERTY()
	uint32 Constitution; //Salud
	UPROPERTY()
	uint32 Charisma; //Diplomacia
	UPROPERTY()
	uint32 Perception; //Intriga
};

/**
 * 
 */
UCLASS()
class LONGLIVETHEKING_API UPeople : public UObject
{
	GENERATED_BODY()
	
public:

	UPeople();

	UFUNCTION()
	//Setea los datos de la persona con los parametros dados
	void SetPeopleData(FString Name, FString LastName, FString Lineage, FString Possesions);
	
	UFUNCTION() 
	//Genera una nueva relacion de opinion para el ID ingresado
	void GenerateRelation(uint32 CharID);

	UFUNCTION()
	FString GetName();
	UFUNCTION()
	FString GetLastName();

private:
	UPROPERTY()
	FString Name;
	UPROPERTY()
	FString LastName;
	UPROPERTY()
	FString Lineage; //TODO: los linajes tienen que ser objetos ya que son exteriores al personaje
	UPROPERTY()
	FString Possesions; //TODO: las posesiones tienen que ser objetos y el personaje tiene que tener una lista de ellas ordenadas por importancia
	UPROPERTY()
	FSCharAttributes CharAttributes;
	UPROPERTY()
	TArray<FString> SaxonNames;

	UFUNCTION()
	void LoadNames();
	
};

