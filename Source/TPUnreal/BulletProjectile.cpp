// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletProjectile.h"

// Sets default values
ABulletProjectile::ABulletProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABulletProjectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &ABulletProjectile::DestroyThisBullet, timeToDie, true, timeToDie);

	sphereCol = Cast<USphereComponent>(reference.GetComponent(this));

	sphereCol->OnComponentBeginOverlap.AddDynamic(this, &ABulletProjectile::OverlapDemo);
}

// Called every frame
void ABulletProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * speed * DeltaTime);
}

void ABulletProjectile::DestroyThisBullet()
{
	Destroy();
}

void ABulletProjectile::OverlapDemo(UPrimitiveComponent* primComp, AActor* overlapedActor, UPrimitiveComponent* otherOverlapedComponent, int32 overInt, bool overBool, const FHitResult& overHit) {


	AMyPlayer* playerCollider = Cast<AMyPlayer>(overlapedActor);
	AMyEnemyActor* enemyCollider = Cast<AMyEnemyActor>(overlapedActor);
	int newScore = 1;
		if (playerCollider != nullptr)
		{
			playerCollider->TakeDamage(damage);
			//UE_LOG(LogTemp, Warning, TEXT("choco con player"));
		}

		if (enemyCollider != nullptr)
		{
			if (otherOverlapedComponent->GetName() == "UpCollider")
			{
				newScore = 5;
			}
			else if (otherOverlapedComponent->GetName() == "MiddleCollider")
			{
				newScore = 3;
			}
			else if (otherOverlapedComponent->GetName() == "DownCollider")
			{
				newScore = 1;
			}
			enemyCollider->TakeDamage(damage,newScore);
			//UE_LOG(LogTemp, Warning, TEXT("choco con enemigo"));
		}

		DestroyThisBullet();
}