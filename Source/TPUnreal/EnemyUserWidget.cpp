// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyUserWidget.h"

UEnemyUserWidget::UEnemyUserWidget(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{

}

void UEnemyUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UEnemyUserWidget::UpdateLifeBar(float lifeAmount, float totalLife)
{
	if (lifeBar)
	{
		lifeBar->SetPercent(lifeAmount / totalLife);
	}
}