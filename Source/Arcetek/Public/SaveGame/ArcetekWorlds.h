// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ArcetekWorlds.generated.h"

/**
 * 
 */
UCLASS()
class ARCETEK_API UArcetekWorlds : public USaveGame
{
	GENERATED_BODY()
public:
	
	UPROPERTY()
	FString ArcetekMasterWorldList = "ArcetekWorlds";
	
	UPROPERTY()
	TArray<FString> Worlds;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FString> GetWorlds();

	void AddWorld(FString WorldName);
	void DeleteWorld(FString WorldName);
};

