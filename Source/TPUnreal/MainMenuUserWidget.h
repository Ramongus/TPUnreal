// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "CreditsUserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "MainMenuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UMainMenuUserWidget(const FObjectInitializer& objectInitializer);

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		UButton* creditsButton;
	UPROPERTY(meta = (BindWidget))
		UButton* playButton;
	UPROPERTY(meta = (BindWidget))
		UButton* quitButton;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> userWidgetClass;

	UFUNCTION(BlueprintCallable)
	void CreditsConfig();
	UFUNCTION(BlueprintCallable)
		void PlayConfig();
	UFUNCTION(BlueprintCallable)
		void QuitConfig();

};
