// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicScreen.h"

// Sets default values for this component's properties
UDynamicScreen::UDynamicScreen()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDynamicScreen::BeginPlay()
{
	Super::BeginPlay();
	AActor* myActor = GetOwner();
	// ...

	if (MaterialRef) 
	{
		DynamicMaterialOne = UMaterialInstanceDynamic::Create(MaterialRef, this);
		DynamicMaterialTwo = UMaterialInstanceDynamic::Create(MaterialRef, this);
		UStaticMeshComponent* mesh = myActor->FindComponentByClass<UStaticMeshComponent>();

		if (mesh)
		{
			mesh->SetMaterial(1, DynamicMaterialOne);
			mesh->SetMaterial(2, DynamicMaterialTwo);

			DynamicMaterialOne->SetTextureParameterValue("Texture", allScreens[0]);
			DynamicMaterialTwo->SetTextureParameterValue("Texture", allScreens[1]);
		}
	}
	
	
	GetWorld()->GetTimerManager().SetTimer(screenOneTimer, this, &UDynamicScreen::ChangeScreenOne, randGen.FRandRange(minTimeToChangeScreen, maxTimeToChangeScreen), true, 1.f);
	GetWorld()->GetTimerManager().SetTimer(screenTwoTimer, this, &UDynamicScreen::ChangeScreenTwo, randGen.FRandRange(minTimeToChangeScreen, maxTimeToChangeScreen), true, 1.f);
}


// Called every frame
void UDynamicScreen::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDynamicScreen::ChangeScreenOne()
{
	int screenIndex = randGen.RandRange(0, allScreens.Num() - 1);
	DynamicMaterialOne->SetTextureParameterValue("Texture", allScreens[screenIndex]);
	if (screenIndex == 0) {
		DynamicMaterialOne->SetVectorParameterValue("PannerSpeed", pannerMove);
	}
	else {
		DynamicMaterialOne->SetVectorParameterValue("PannerSpeed", pannerStop);
	}
}

void UDynamicScreen::ChangeScreenTwo()
{
	int screenIndex = randGen.RandRange(0, allScreens.Num() - 1);
	DynamicMaterialTwo->SetTextureParameterValue("Texture", allScreens[screenIndex]);
	if (screenIndex == 0) {
		DynamicMaterialTwo->SetVectorParameterValue("PannerSpeed", pannerMove);
	}
	else {
		DynamicMaterialTwo->SetVectorParameterValue("PannerSpeed", pannerStop);
	}
}

