// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/ArcetekGameModeBase.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "SaveGame/ArcetekSaveGame.h"
#include "Data/ActorSaveData.h"

/*IArcetekable* _Arcetekable = Cast<IArcetekable>(ActorToSave);
if (_Arcet1ekable) {

	FArcetekableSaveData ArcetekableSaveData;
	ArcetekableSaveData.RowNameId = _Arcetekable->GetRowNameId();
	ArcetekableSaveData.Transform = ActorToSave->GetTransform();

	FMemoryWriter MemWriter(ArcetekableSaveData.ArcetekableData);
	FObjectAndNameAsStringProxyArchive Ar(MemWriter, true);
	Ar.ArIsSaveGame = true;
	Ar.ArNoDelta = true;
	ActorToSave->Serialize(Ar);

	if (ArcetekSaveGame) {
		UE_LOG(LogTemp, Warning, TEXT("Save Data GUID: %s"), *_Arcetekable->GetArcetekableGuid().ToString())
			ArcetekSaveGame->ArcetekableObjs.Add(_Arcetekable->GetArcetekableGuid().ToString(), ArcetekableSaveData);
		UGameplayStatics::SaveGameToSlot(ArcetekSaveGame, "ArcetekTest", 0);
	}
	return true;
*/

/*
	Get all actors with ISaveable and Save The Objects to the level.

*/

AArcetekGameModeBase::AArcetekGameModeBase()
{

}

void AArcetekGameModeBase::SaveAllPlacedActors(UArcetekSaveGame* SaveGame, TArray<AActor*> ActorsToSave)
{
	int32 ActorsNum = ActorsToSave.Num();
	SaveGame->EmptyWorldData();
	for (int32 i = 0; i < ActorsNum; i++) {
		TSubclassOf<AActor>ActorClass = ActorsToSave[i]->GetClass();
		FTransform T = ActorsToSave[i]->GetActorTransform();

		FActorSaveData Data = FActorSaveData(ActorsToSave[i]->GetClass(), ActorsToSave[i]->GetActorTransform());
		SaveGame->AddActorData(Data);
	}
}
