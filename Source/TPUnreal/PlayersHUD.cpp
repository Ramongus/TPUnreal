// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersHUD.h"

APlayersHUD::APlayersHUD()
{

}

void APlayersHUD::BeginPlay()
{
	Super::BeginPlay();
	if (usetWidgetClass)
	{
		playersUserWidget = CreateWidget<UPlayersUserWidget>(GetWorld(), usetWidgetClass);

		if (playersUserWidget)
		{
			playersUserWidget->AddToViewport();
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