// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuUserWidget.h"

UMainMenuUserWidget::UMainMenuUserWidget(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{

}

void UMainMenuUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainMenuUserWidget::CreditsConfig()
{
	UCreditsUserWidget* creditsWidget = CreateWidget<UCreditsUserWidget>(GetWorld(), userWidgetClass);
	if (creditsWidget)
	{
		creditsWidget->AddToViewport();
	}
	UE_LOG(LogTemp, Warning, TEXT("va a los creditos"));
}

void UMainMenuUserWidget::PlayConfig()
{
	UGameplayStatics::OpenLevel(this, FName("DemoLevel"));
}

void UMainMenuUserWidget::QuitConfig()
{
	UE_LOG(LogTemp, Warning, TEXT("salir del juego"));
}

