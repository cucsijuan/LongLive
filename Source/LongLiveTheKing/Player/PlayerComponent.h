// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "People.h"
#include "Components/ActorComponent.h"
#include "PlayerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LONGLIVETHEKING_API UPlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	//UPeople CharData;

	UPROPERTY(EditDefaultsOnly, Category = "Player Setup")
	FString Name;
	UPROPERTY(EditDefaultsOnly, Category = "Player Setup")
	FString LastName;
	
};
