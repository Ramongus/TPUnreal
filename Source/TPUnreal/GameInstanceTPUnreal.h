// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	int currentTime;
	int playersLifes;

	virtual void Init() override;
	
};
