// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "TPUnrealGameState.h"
#include "GameFramework/GameModeBase.h"
#include "TPUnrealGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API ATPUnrealGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
		float timeToSpawnPlayer;
	UPROPERTY(EditDefaultsOnly)
		int pointsToFinishRound = 10;

public:
	
	bool IsRoundFinished() const;
};
