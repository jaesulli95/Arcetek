// Fill out your copyright notice in the Description page of Project Settings.


#include "Instances/ArcetekGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGame/ArcetekWorlds.h"
#include "SaveGame/ArcetekSaveGame.h"

void UArcetekGameInstance::Init()
{
	Super::Init();

	//If Master World List Doesnt Exist Create it

	if (!UGameplayStatics::DoesSaveGameExist("ArcetekWorldList", 0)) {
		Worlds = Cast<UArcetekWorlds>(UGameplayStatics::CreateSaveGameObject(UArcetekWorlds::StaticClass()));
		UGameplayStatics::SaveGameToSlot(Worlds, "ArcetekWorldList", 0);
	}
	else {
		Worlds = Cast<UArcetekWorlds>(UGameplayStatics::LoadGameFromSlot("ArcetekWorldList", 0));
	}

	//Set the default world

}

EWorldCreateResult UArcetekGameInstance::CreateWorld(FString WorldName)
{
	bool bDoesWorldExist = UGameplayStatics::DoesSaveGameExist(WorldName, 0);
	if (bDoesWorldExist) {
		return EWorldCreateResult::EWCR_GameExists;
	}

	Worlds->AddWorld(WorldName);
	bool bSaveResult = UGameplayStatics::SaveGameToSlot(Worlds, "ArcetekWorldList", 0);

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

TArray<FString> UArcetekGameInstance::GetGameWorlds()
{
	if (Worlds) {
		return Worlds->GetWorlds();
	}
	return TArray<FString>();
}

void UArcetekGameInstance::LoadWorldData(FString WorldName)
{
	ArcetekWorld = Cast<UArcetekSaveGame>(UGameplayStatics::LoadGameFromSlot(WorldName, 0));
}

bool UArcetekGameInstance::CanTransition()
{
	if (ArcetekWorld) {
		return true;
	}
	return false;
}
