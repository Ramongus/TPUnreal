// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "MyEnemyActor.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BulletProjectile.generated.h"

UCLASS()
class TPUNREAL_API ABulletProjectile : public AActor
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	ABulletProjectile();

	UPROPERTY(EditAnywhere)
		float speed;

	UPROPERTY(EditAnywhere)
		float timeToDie;

	UPROPERTY(EditAnywhere)
		int  damage;

	UPROPERTY(EditAnywhere)
		FComponentReference reference;

	UPROPERTY()
		USphereComponent* sphereCol;

	FTimerHandle myTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void DestroyThisBullet();

	UFUNCTION()
		void OverlapDemo(UPrimitiveComponent* primComp, AActor* overlapedActor, UPrimitiveComponent* otherOverlapedComponent, int32 overInt, bool overBool, const FHitResult& overHit);
};
