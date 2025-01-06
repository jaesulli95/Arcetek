// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
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

USTRUCT(Blueprintable, BlueprintType)
struct FArcetekableData : public FTableRowBase {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EArcetekableType Type;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bGrounded = true;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector Offset = FVector();
};

USTRUCT(Blueprintable, BlueprintType)
struct FArcetekableSaveData {
	GENERATED_BODY();
public:
	UPROPERTY()
	FName RowNameId;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	TArray<uint8> Data;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class ARCETEK_API UArcetekComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArcetekComponent();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Data")
	float RotationRate = 10.0F;

	UPROPERTY(BlueprintReadOnly)
	bool bIsBuilding = false;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> CurrentActor;

	UFUNCTION(BlueprintCallable)
	void SetCurrentArcetekable(AActor* ActorToModify);

	UFUNCTION(BlueprintCallable, Category="Arcetek|Utility")
	virtual void EnterBuildMode(bool isBuilding);

	UFUNCTION(BlueprintCallable, Category="Arcetek|Utility")
	void RotateActor(float Rate);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
