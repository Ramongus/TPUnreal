// Fill out your copyright notice in the Description page of Project Settings.


#include "TPUnrealGameState.h"

void ATPUnrealGameState::SetScore(int value)
{
	score += value;
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (hud)	hud->UpdateScoreText(score);
	
}

void ATPUnrealGameState::OnRoundFinished()
{
	 UE_LOG(LogTemp, Warning, TEXT("termino el round"));
	 APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	 if (hud)	hud->UpdateMainText("YOU WON! FINAL SCORE: " + FString::FromInt(score));
}



void ATPUnrealGameState::AddDestroyedEnemy()
{
	currentEnemiesDestroyed++;
	ATPUnrealGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATPUnrealGameModeBase>();
	if (gameMode->IsRoundFinished())
	{
		OnRoundFinished();
	}
}

void ATPUnrealGameState::OnRoundLost()
{
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (hud)	hud->UpdateMainText("YOU LOST! FINAL SCORE: " + FString::FromInt(score));
}

void ATPUnrealGameState::OnRoundDied()
{
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (hud)	hud->UpdateMainText("YOU DIED, WAITING FOR RESPAWN");
}