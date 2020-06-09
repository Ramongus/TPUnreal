// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "BulletProjectile.h"
#include "GameFramework/Actor.h"
#include "MyPlayer.generated.h"

UCLASS()
class TPUNREAL_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

	UPROPERTY(EditDefaultsOnly)
		float speed = 10.0f;
	UPROPERTY(EditDefaultsOnly)
		float rotationSpeed = 2.0f;
	UPROPERTY(EditDefaultsOnly)
		float lookUpSpeed = 2.0f;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABulletProjectile> bulletPrefab;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
	void Shoot();
};
