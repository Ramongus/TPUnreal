// Fill out your copyright notice in the Description page of Project Settings.


#include "TPUnrealGameState.h"

void ATPUnrealGameState::SetScore(int value)
{
	score += value;
	ATPUnrealGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATPUnrealGameModeBase>();
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (hud)	hud->UpdateScoreText(score);
	if (gameMode->IsRoundFinished())
	{
		OnRoundFinished();
	}
}

void ATPUnrealGameState::OnRoundFinished()
{
	 UE_LOG(LogTemp, Warning, TEXT("termino el round"));
}