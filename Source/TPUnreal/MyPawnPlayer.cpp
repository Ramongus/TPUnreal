// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawnPlayer.h"
#include "Components/InputComponent.h"

// Sets default values
AMyPawnPlayer::AMyPawnPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawnPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawnPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawnPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawnPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawnPlayer::MoveRight);
}

void AMyPawnPlayer::MoveForward(float value) {

	FVector forward = GetActorForwardVector().GetSafeNormal();

	SetActorLocation(GetActorLocation() + forward * speed * value);
}

void AMyPawnPlayer::MoveRight(float value) {

	FVector right = GetActorRightVector().GetSafeNormal();

	SetActorLocation(GetActorLocation() + right * speed * value);
}

