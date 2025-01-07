// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorSaveData.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FActorSaveData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<AActor> Class;

	UPROPERTY(BlueprintReadOnly)
	FTransform Transform;

	FActorSaveData() {

	}

	FActorSaveData(TSubclassOf<AActor> ActorClass, FTransform ActorTransform) {
		Class = ActorClass;
		Transform = ActorTransform;
	}
};