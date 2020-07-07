// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"

// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APowerUp::BeginPlay()
{
	Super::BeginPlay();
	
	sphereCol = Cast<USphereComponent>(reference.GetComponent(this));

	sphereCol->OnComponentBeginOverlap.AddDynamic(this, &APowerUp::OverlapDemo);
}

// Called every frame
void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerUp::OverlapDemo(UPrimitiveComponent* primComp, AActor* overlapedActor, UPrimitiveComponent* otherOverlapedComponent, int32 overInt, bool overBool, const FHitResult& overHit) 
{
	AMyPlayer* playerCollider = Cast<AMyPlayer>(overlapedActor);

	if (playerCollider != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("POWER UP"));
		playerCollider->FireBurst();
		Destroy();
	}
}

