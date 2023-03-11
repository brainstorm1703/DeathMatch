// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathMatchGameMode.h"
#include "DeathMatchHUD.h"
#include "DeathMatchCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADeathMatchGameMode::ADeathMatchGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADeathMatchHUD::StaticClass();
}
