// Fill out your copyright notice in the Description page of Project Settings.


#include "CreditsUserWidget.h"

UCreditsUserWidget::UCreditsUserWidget(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{

}

void UCreditsUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UCreditsUserWidget::BackToMenu()
{
	
	UMainMenuUserWidget* menuWidget = CreateWidget<UMainMenuUserWidget>(GetWorld(), userWidgetClass );
	if (menuWidget)
	{
		menuWidget->AddToViewport();
	}
	UE_LOG(LogTemp, Warning, TEXT("va de nuevo al menu"));
}