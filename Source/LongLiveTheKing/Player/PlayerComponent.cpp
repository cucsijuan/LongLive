// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerComponent.h"
#include "People.h"

// Sets default values for this component's properties
UPlayerComponent::UPlayerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
 

// Called when the game starts
void UPlayerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CharData = NewObject<UPeople>(this);
	CharData->SetPeopleData(Name, LastName, "none", "none");
	
}


// Called every frame
void UPlayerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UPlayerComponent::GetName()
{
	return CharData->GetName();
}

FString UPlayerComponent::GetLastName()
{
	return CharData->GetLastName();
}

