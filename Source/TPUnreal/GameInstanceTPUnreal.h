// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPUnrealGameModeBase.h"
#include "Engine//World.h"
#include "Engine/GameInstance.h"
#include "GameInstanceTPUnreal.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API UGameInstanceTPUnreal : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	int currentTime;
	UPROPERTY(BlueprintReadWrite)
	int playersLifes;
	UPROPERTY(BlueprintReadWrite)
	int points;

	virtual void Init() override;
	
};
