// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/ArcetekSaveGame.h"

TArray<FActorSaveData> UArcetekSaveGame::GetWorldData()
{
	return WorldData;
}

void UArcetekSaveGame::EmptyWorldData()
{
	WorldData.Empty();
}

void UArcetekSaveGame::AddActorData(FActorSaveData ActorData)
{
	WorldData.Add(ActorData);
}
