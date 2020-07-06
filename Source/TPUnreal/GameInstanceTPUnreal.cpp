// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceTPUnreal.h"

void UGameInstanceTPUnreal::Init()
{
	//ATPUnrealGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATPUnrealGameModeBase>();
	//playersLifes = gameMode->playersLifes;
	UE_LOG(LogTemp,Warning,TEXT("empiezo con: %i vidas"),playersLifes)
}