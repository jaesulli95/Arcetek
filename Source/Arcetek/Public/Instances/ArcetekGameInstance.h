// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ArcetekGameInstance.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWorldCreateResult : uint8 {
	EWCR_Created,
	EWCR_GameExists,
};

UCLASS()
class ARCETEK_API UArcetekGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category="Arcetek|Worlds|Utility")
	EWorldCreateResult CreateWorld(FString WorldName);

	UFUNCTION(BlueprintCallable, Category="Arcetek|Worlds|Utility")
	bool DeleteWorld(FString WorldName);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FString> GetGameWorlds();

	UFUNCTION(BlueprintCallable)
	void LoadWorldData(FString WorldName);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanTransition();

protected:
	UPROPERTY()
	class UArcetekWorlds* Worlds;

	UPROPERTY()
	class UArcetekSaveGame* ArcetekWorld;
};
