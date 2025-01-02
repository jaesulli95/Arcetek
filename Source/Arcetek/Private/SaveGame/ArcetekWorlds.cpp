// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/ArcetekWorlds.h"

TArray<FString> UArcetekWorlds::GetWorlds()
{
	return Worlds;
}

void UArcetekWorlds::AddWorld(FString WorldName)
{
	Worlds.Add(WorldName);
}

void UArcetekWorlds::DeleteWorld(FString WorldName)
{
	Worlds.Remove(WorldName);
}
