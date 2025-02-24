// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcetekGameModeBase.generated.h"

/**
 * 
 */

class UArcetekSaveGame;

UCLASS()
class ARCETEK_API AArcetekGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArcetekGameModeBase();

	UFUNCTION(BlueprintCallable)
	void SaveAllPlacedActors(UArcetekSaveGame* SaveGame, TArray<AActor*> ActorsToSave);

	UFUNCTION(BlueprintCallable)
	void LoadActorData(AActor* StagedActor, TArray<uint8> Data);
};
