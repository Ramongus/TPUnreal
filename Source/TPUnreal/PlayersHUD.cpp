// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersHUD.h"

APlayersHUD::APlayersHUD()
{

}

void APlayersHUD::BeginPlay()
{
	Super::BeginPlay();

	FString levelname = GetWorld()->GetFirstPlayerController()->GetLevel()->GetOuter()->GetName();
	
	if (levelname == "MainMenu")
	{
		UE_LOG(LogTemp, Warning, TEXT("esta el menu"));
	}
	else if (usetWidgetClass)
	{
		playersUserWidget = CreateWidget<UPlayersUserWidget>(GetWorld(), usetWidgetClass);

		if (playersUserWidget)
		{
			playersUserWidget->AddToViewport();
			playersUserWidget->UpdateMainText("");
		}
	}
}

void APlayersHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayersHUD::DrawHUD()
{
	Super::DrawHUD();
}

void APlayersHUD::UpdateLifeBar(float lifeAmount, float totalLifeAmount)
{
	if (playersUserWidget)
	{
		playersUserWidget->UpdateLifeBar(lifeAmount, totalLifeAmount);
	}
}

void APlayersHUD::UpdateScoreText(int value)
{
	if (playersUserWidget)
	{
		playersUserWidget->UpdateScoreText(value);
	}
}

void APlayersHUD::UpdateMainText(FString text)
{
	if (playersUserWidget)
	{
		playersUserWidget->UpdateMainText(text);
	}
}
