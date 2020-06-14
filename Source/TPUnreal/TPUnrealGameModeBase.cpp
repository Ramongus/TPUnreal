// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "TPUnrealGameModeBase.h"

bool ATPUnrealGameModeBase::IsRoundFinished() const
{
	ATPUnrealGameState* myGameState = GetWorld()->GetGameState<ATPUnrealGameState>();
	return myGameState->GetEnemiesDestroyed() >= enemiesDestroyed;
}