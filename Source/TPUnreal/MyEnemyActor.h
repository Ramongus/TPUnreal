// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/World.h"
#include "BulletProjectile.h"
#include "Enemy_AnimIns.h"
#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "GameFramework/Actor.h"
#include "MyEnemyActor.generated.h"

UCLASS()
class TPUNREAL_API AMyEnemyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyEnemyActor();

	UPROPERTY(EditAnywhere)
		UChildActorComponent* gunPointPos;

	UPROPERTY(EditAnywhere)
		float speed;

	UPROPERTY(EditAnywhere)
		float distanceToStop;

	UPROPERTY(EditAnywhere)
		float timeBetweenShoot;

	UPROPERTY(EditAnywhere)
		bool canMove;

	UPROPERTY(EditAnywhere)
		bool canShoot;

	UPROPERTY(EditAnywhere)
		bool canRotate;

	UPROPERTY(EditAnywhere)
		int totalLife;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABulletProjectile> bulletPrefab;

	FTimerHandle myTimer;

	UPROPERTY()
		UEnemy_AnimIns* animatorEnemy;

	AActor* theplayer;


	bool died;
	int currentLife;

	UPROPERTY()
		UAudioComponent* audioComp;

	UPROPERTY(EditAnywhere)
		USoundCue* shootSound;

	UPROPERTY(EditAnywhere)
		USoundCue* hitSound;

	UPROPERTY(EditAnywhere)
		USoundCue* deathSound;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward();

	void CheckIdle();

	UFUNCTION()
		void TakeDamage(int damage);

	UFUNCTION()
		void Shoot();

	UFUNCTION()
		void DieAction();

};
