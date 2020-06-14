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
	if (FadeOutAnim)
	{
		UE_LOG(LogTemp, Warning, TEXT("fadeanimaaa"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no hay fadeanimaaa"));
	}
	if (FadeOutAnim && lifeAmount<=0)
	{
		UE_LOG(LogTemp, Warning, TEXT("fadeanim"));
		PlayAnimation(FadeOutAnim, 0.f, 1, EUMGSequencePlayMode::Forward, 1);
	}
	if (FadeOutAnim && lifeAmount == totalLife)
	{
		PlayAnimation(FadeOutAnim, 1.0f, 1, EUMGSequencePlayMode::Reverse, 1);
	}
}

void UPlayersUserWidget::UpdateScoreText(int value)
{
	if (pointsText)
	{
		pointsText->SetText(FText::FromString("POINTS: " + FString::FromInt(value)));
	}
}

void UPlayersUserWidget::UpdateMainText(FString text)
{
	if (mainText)
	{
		
		mainText->SetText(FText::FromString(text));
	}
}