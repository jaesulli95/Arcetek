// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/ArcetekGameModeBase.h"

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