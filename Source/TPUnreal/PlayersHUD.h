// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "PlayersUserWidget.h"
#include "PlayersHUD.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API APlayersHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	APlayersHUD();

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> usetWidgetClass;

	void UpdateLifeBar(float lifeAmount , float totalLifeAmount);
	void UpdateScoreText(int value);
	void UpdateMainText(FString text);
	

	virtual void DrawHUD();
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

private:

	UPlayersUserWidget* playersUserWidget;
};
