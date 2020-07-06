// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPUnrealGameModeBase.h"
#include "Engine/World.h"
#include "GameInstanceTPUnreal.h"
#include "PlayersHUD.h"
#include "GameFramework/GameStateBase.h"
#include "TPUnrealGameState.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API ATPUnrealGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:
	
	int score = 0;
	int currentRound = 1;
	int currentEnemiesDestroyed;

public:
	int GetScore() const { return score; }
	int GetEnemiesDestroyed() const { return currentEnemiesDestroyed; }
	void SetScore(int value);
	void AddDestroyedEnemy();
	void OnRoundFinished();
	void OnRoundLost();
	void OnRoundDied();
};
