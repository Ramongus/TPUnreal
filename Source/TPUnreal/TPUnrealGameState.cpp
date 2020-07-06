// Fill out your copyright notice in the Description page of Project Settings.


#include "TPUnrealGameState.h"

void ATPUnrealGameState::SetScore(int value)
{
	score += value;
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	UGameInstanceTPUnreal* mygi = Cast<UGameInstanceTPUnreal>(GetGameInstance());
	if (mygi)
	{
		mygi->points = score;
		//UE_LOG(LogTemp, Warning, TEXT("puntos con: %i puntos"), mygi->points);
	}

	if (hud)	hud->UpdateScoreText(score);
	
}

void ATPUnrealGameState::OnRoundFinished()
{
	 UE_LOG(LogTemp, Warning, TEXT("termino el round"));
	 APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	 GetWorld()->GetCurrentLevel()->GetName();
	 FString levelname = GetWorld()->GetFirstPlayerController()->GetLevel()->GetOuter()->GetName();
	// if (hud)	hud->UpdateMainText(levelname + "LEVEL FINISHED! SCORE: " + FString::FromInt(score));
	 if (levelname == "DemoLevel")
	 {
		 if (hud)	hud->UpdateMainText("LEVEL FINISHED! SCORE: " + FString::FromInt(score));
	 }
	 else if (levelname == "DemoLevel2")
	 {
		 if (hud)	hud->UpdateMainText("YOU WON! FINAL SCORE: " + FString::FromInt(score));
	 }

	 //UE_LOG(LogTemp, Warning, TEXT("nombre del level es %i "), TEXT(levelname));
	
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
	if (hud)	hud->UpdateMainText("YOU LOST! FINAL SCORE: " + FString::FromInt(score) + "\n PRESS R TO RESTART");
}

void ATPUnrealGameState::OnRoundDied()
{
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (hud)	hud->UpdateMainText("YOU DIED, WAITING FOR RESPAWN");
}