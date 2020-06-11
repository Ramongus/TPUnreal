// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersUserWidget.h"

UPlayersUserWidget::UPlayersUserWidget(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{

}

void UPlayersUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UPlayersUserWidget::UpdateLifeBar(float lifeAmount,float totalLife)
{
	if (lifeBar)
	{
		lifeBar->SetPercent(lifeAmount/totalLife);
	}
}