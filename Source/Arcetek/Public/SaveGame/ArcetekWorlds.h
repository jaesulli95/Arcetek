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
	TArray<FString> Worlds;

};
