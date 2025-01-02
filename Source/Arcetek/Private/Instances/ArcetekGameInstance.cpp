// Fill out your copyright notice in the Description page of Project Settings.


#include "Instances/ArcetekGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGame/ArcetekWorlds.h"
#include "SaveGame/ArcetekSaveGame.h"

void UArcetekGameInstance::Init()
{
	Super::Init();

	//If Master World List Doesnt Exist Create it
}

EWorldCreateResult UArcetekGameInstance::CreateWorld(FString WorldName)
{
	bool bDoesWorldExist = UGameplayStatics::DoesSaveGameExist(WorldName, 0);
	if (bDoesWorldExist) {
		return EWorldCreateResult::EWCR_GameExists;
	}

	Worlds->AddWorld(WorldName);
	bool bSaveResult = UGameplayStatics::SaveGameToSlot(Worlds, Worlds->ArcetekMasterWorldList, 0);

	if (bSaveResult) {
		//Create The New Save Game Object Here
		UArcetekSaveGame* NewArcetekWorld = Cast<UArcetekSaveGame>(UGameplayStatics::CreateSaveGameObject(UArcetekSaveGame::StaticClass()));
		UGameplayStatics::SaveGameToSlot(NewArcetekWorld, WorldName, 0);
	}
	return EWorldCreateResult::EWCR_Created;
}

bool UArcetekGameInstance::DeleteWorld(FString WorldName)
{
	return false;
}
