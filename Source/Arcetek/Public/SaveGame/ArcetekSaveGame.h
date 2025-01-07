// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Data/ActorSaveData.h"
#include "ArcetekSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ARCETEK_API UArcetekSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FActorSaveData> WorldData;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FActorSaveData> GetWorldData();

	void EmptyWorldData();
	void AddActorData(FActorSaveData ActorData);

};
