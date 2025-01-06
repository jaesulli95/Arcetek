// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ArcetekComponent.h"

// Sets default values for this component's properties
UArcetekComponent::UArcetekComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UArcetekComponent::SetCurrentArcetekable(AActor* ActorToModify)
{
	CurrentActor = ActorToModify;
}

void UArcetekComponent::EnterBuildMode(bool isBuilding)
{
	bIsBuilding = isBuilding;
}

void UArcetekComponent::RotateActor(float Rate)
{
	if (CurrentActor == nullptr) {
		return;
	}

	FRotator Rotation = CurrentActor->GetActorRotation();
	CurrentActor->SetActorRotation(FRotator(Rotation.Pitch, Rotation.Yaw + Rate, Rotation.Roll));
}

// Called when the game starts
void UArcetekComponent::BeginPlay()
{
	Super::BeginPlay();	
}

