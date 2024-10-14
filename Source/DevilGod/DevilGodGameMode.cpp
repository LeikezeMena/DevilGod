// Copyright Epic Games, Inc. All Rights Reserved.

#include "DevilGodGameMode.h"
#include "DevilGodPlayerController.h"
#include "DevilGodCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADevilGodGameMode::ADevilGodGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADevilGodPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}