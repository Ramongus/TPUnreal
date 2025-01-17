// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "BulletProjectile.h"
#include "TPUnrealGameState.h"
#include "GameInstanceTPUnreal.h"
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
		float speed = 1.0f;
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

	UPROPERTY()
		UAudioComponent* audioComp;

	UPROPERTY(EditAnywhere)
		USoundCue* hitSound;

	UPROPERTY(EditAnywhere)
		USoundCue* deathSound;

	UPROPERTY(EditAnywhere)
		USoundCue* powerUpSound;

	UPROPERTY(EditAnywhere)
		USoundCue* debufSound;

	UPROPERTY(EditAnywhere)
		float timeBurst;

	UPROPERTY(EditAnywhere)
		float fireRateInBurst;
	UPROPERTY(EditAnywhere)
		float timeSlowed = 3.0f;
	UPROPERTY(EditAnywhere)
		float slowMultiplier = 0.5f;

	bool burst;
	
	UGameInstanceTPUnreal* myGI;
	FTimerHandle myTimer;
	FTimerHandle otherTimer;
	FTimerHandle slowTimer;

	int timesToDie;
	int timeToRespawn;
	float respawnTimer;
	bool hastoRestart;
	int timer;
	bool slowed;

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
	UFUNCTION()
		void PlaySound(USoundCue* sound);

	UFUNCTION()
		void UpdateTimer();

	UFUNCTION()
		void FireBurst();

	UFUNCTION()
		void UnActiveBurst();

	UFUNCTION()
		void CreateBullet();

	UFUNCTION()
		void Slow();

	UFUNCTION()
		void NormalSpeed();
};
