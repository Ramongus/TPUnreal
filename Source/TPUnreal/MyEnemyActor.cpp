// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyActor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyEnemyActor::AMyEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (canMove == true)
	{
		AMyEnemyActor::MoveForward();
	}
	AMyEnemyActor::CheckIdle();
	
}

void AMyEnemyActor::CheckIdle()
{
	float dis = FMath::Abs(FVector::Dist(player->GetActorLocation(), GetActorLocation()));
	if (dis <= distanceToStop)
	{
		canMove = false;
	}
	else
	{
		canMove = true;
	}
}

void AMyEnemyActor::MoveForward()
{
	

	FVector dirVector = player->GetActorLocation() - GetActorLocation();
	dirVector = FVector(dirVector.X, dirVector.Y, 0);
	SetActorLocation(GetActorLocation() + dirVector.GetSafeNormal() * speed);

	FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), player->GetActorLocation());
	
	lookRotation = FRotator(0, lookRotation.Yaw, 0);

	SetActorRotation(lookRotation, ETeleportType::None);
}

