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
		int timeToSpawnPlayer;
	UPROPERTY(EditDefaultsOnly)
		int playersLifes;
	UPROPERTY(EditDefaultsOnly)
		float timeToSpawnEnemy;
	UPROPERTY(EditDefaultsOnly)
		int pointsToFinishRound = 10;
	UPROPERTY(EditDefaultsOnly)
		int enemiesToSpawn = 2;

	int enemiesDestroyed = 2;
	float timerToSpawn = 0;

	UPROPERTY(BlueprintReadWrite)
	int myTimer;
	UPROPERTY(BlueprintReadWrite)
	int myBeginTimer;

public:
	
	UFUNCTION(BlueprintCallable)
	bool IsRoundFinished() const;
};
