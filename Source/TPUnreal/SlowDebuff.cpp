// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowDebuff.h"

// Sets default values
ASlowDebuff::ASlowDebuff()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlowDebuff::BeginPlay()
{
	Super::BeginPlay();
	
	sphereCol = Cast<USphereComponent>(reference.GetComponent(this));

	sphereCol->OnComponentBeginOverlap.AddDynamic(this, &APowerUp::OverlapDemo);
}

// Called every frame
void ASlowDebuff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlowDebuff::OverlapDemo(UPrimitiveComponent* primComp, AActor* overlapedActor, UPrimitiveComponent* otherOverlapedComponent, int32 overInt, bool overBool, const FHitResult& overHit) {

	AMyPlayer* playerCollider = Cast<AMyPlayer>(overlapedActor);
	if (playerCollider != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SlowBuff"));
		playerCollider->Slow();
		Destroy();
	}
}

