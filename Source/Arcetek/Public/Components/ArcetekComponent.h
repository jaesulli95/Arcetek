// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArcetekComponent.generated.h"

UENUM(BlueprintType)
enum class EArcetekBuildMode : uint8 {
	EABM_Standard UMETA(DisplayName = "Standard"),
	EABM_Isometric UMETA(DisplayName = "Isometric")
};

UENUM(BlueprintType)
enum class EArcetekableType : uint8 {
	EAT_Structure UMETA(DisplayName = "Structure"),
	EAT_NPC UMETA(DisplayName = "NPC")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCETEK_API UArcetekComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArcetekComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
