// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ArcetekComponent.h"
#include "Kismet/GameplayStatics.h"

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
	BuildStateUpdated.Broadcast(bIsBuilding);
}

void UArcetekComponent::RotateActor(float Rate)
{
	if (CurrentActor == nullptr) {
		return;
	}

	FRotator Rotation = CurrentActor->GetActorRotation();
	CurrentActor->SetActorRotation(FRotator(Rotation.Pitch, Rotation.Yaw + Rate, Rotation.Roll));
}

void UArcetekComponent::TryCreateArcetekable(FArcetekableData Data)
{
	if (CurrentActor != nullptr) {
		return;
	}
	AActor* NewActor = GetWorld()->SpawnActor<AActor>(Data.ActorClass, FTransform());
	if (NewActor) {
		SetCurrentArcetekable(NewActor);
	}
}

// Called when the game starts
void UArcetekComponent::BeginPlay()
{
	Super::BeginPlay();	
}

