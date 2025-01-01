// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcetekGameMode.h"
#include "ArcetekCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArcetekGameMode::AArcetekGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
