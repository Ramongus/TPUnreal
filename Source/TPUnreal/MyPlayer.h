// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "BulletProjectile.h"
#include "TPUnrealGameState.h"
#include "WeaponAnimInstance.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
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

	UPROPERTY(EditDefaultsOnly)
		float totalLife = 5;

	float currentLife = 5;
	bool died;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABulletProjectile> bulletPrefab;
	UPROPERTY(EditAnywhere)
		FComponentReference refToSpawnBulletPoint;

	USceneComponent* bulletSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWeaponAnimInstance* weaponAnim;

	int timesToDie;
	int timeToRespawn;
	float respawnTimer;
	bool hastoRestart;
	int timer;

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
	void JumpAction();
	UFUNCTION()
		void TakeDamage(int damage);
	UFUNCTION()
		void DieAction();
	UFUNCTION()
		void RestartGame();
};
