// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "PlayersUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API UPlayersUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPlayersUserWidget(const FObjectInitializer& objectInitializer);

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* pointsText;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* lifeBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* mainText;



	UPROPERTY(meta = (BindWidgetAnim))
		UWidgetAnimation* FadeOutAnim;


	void UpdateLifeBar(float lifeAmount,float totalLife);
	void UpdateScoreText(int value);
	void UpdateMainText(FString text);
	void UpdateTimerText(FString text);
};
