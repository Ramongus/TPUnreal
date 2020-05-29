// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Components/InputComponent.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
}

void AMyPlayer::MoveForward(float value) {

	if (value != 0) {
		FVector forward = GetActorForwardVector().GetSafeNormal();
		AddMovementInput(forward, speed * value);
	}
}

void AMyPlayer::MoveRight(float value) {

	if (value != 0) {
		FVector right = GetActorRightVector().GetSafeNormal();
		AddMovementInput(right, speed * value);
	}
}
