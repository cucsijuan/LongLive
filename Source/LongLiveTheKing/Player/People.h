// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "People.generated.h"

struct SCharAttributes
{
	uint32 Strength;  //Marcial
	uint32 Constitution; //Salud
	uint32 Charisma; //Diplomacia
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
	//Setea los datos de la persona con los parametros dados
	void SetPeopleData(FString Name, FString LastName, FString Lineage, FString Possesions);
	//Genera una nueva relacion de opinion para el ID ingresado
	void GenerateRelation(uint32 CharID);
private:
	FString Name;
	FString LastName;
	FString Lineage; //TODO: los linajes tienen que ser objetos ya que son exteriores al personaje
	FString Possesions; //TODO: las posesiones tienen que ser objetos y el personaje tiene que tenes una lista de ellas ordenadas por importancia
	SCharAttributes CharAttributes;
	
};

