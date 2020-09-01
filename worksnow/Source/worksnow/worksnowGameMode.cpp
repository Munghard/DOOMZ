// Copyright Epic Games, Inc. All Rights Reserved.

#include "worksnowGameMode.h"
#include "worksnowHUD.h"
#include "worksnowCharacter.h"
#include "UObject/ConstructorHelpers.h"

AworksnowGameMode::AworksnowGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/MeatMan"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AworksnowHUD::StaticClass();
}
