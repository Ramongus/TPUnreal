// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Math/RandomStream.h"
#include "Math/Color.h"
#include "DynamicScreen.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPUNREAL_API UDynamicScreen : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDynamicScreen();

	UPROPERTY(EditAnywhere)
		UMaterialInterface* MaterialRef;
	
	UPROPERTY(VisibleAnywhere)
		UMaterialInstanceDynamic* DynamicMaterialOne;

	UPROPERTY(VisibleAnywhere)
		UMaterialInstanceDynamic* DynamicMaterialTwo;

	UPROPERTY(EditAnywhere)
		TArray<UTexture*> allScreens;

	UPROPERTY(EditAnywhere)
		float minTimeToChangeScreen;

	UPROPERTY(EditAnywhere)
		float maxTimeToChangeScreen;

	FTimerHandle screenOneTimer;
	FTimerHandle screenTwoTimer;

	FRandomStream randGen;

	UPROPERTY(EditAnywhere)
		FLinearColor pannerMove;

	UPROPERTY(EditAnywhere)
		FLinearColor pannerStop;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void ChangeScreenOne();

	UFUNCTION()
		void ChangeScreenTwo();
		
};
