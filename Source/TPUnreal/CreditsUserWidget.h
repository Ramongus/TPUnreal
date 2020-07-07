// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/HUD.h"
#include "Engine/World.h"
#include "MainMenuUserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "CreditsUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API UCreditsUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UCreditsUserWidget(const FObjectInitializer& objectInitializer);

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> userWidgetClass;

	UPROPERTY(meta = (BindWidget))
		UButton* menuButton;

	UFUNCTION(BlueprintCallable)
		void BackToMenu();

private:

	
};
