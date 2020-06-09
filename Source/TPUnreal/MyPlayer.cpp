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
	PlayerInputComponent->BindAxis("Turn", this, &AMyPlayer::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyPlayer::LookUp);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayer::Shoot);
}

void AMyPlayer::MoveForward(float value) {

	FVector forward = GetActorForwardVector().GetSafeNormal();
	AddMovementInput(forward, speed * value);
}

void AMyPlayer::MoveRight(float value) {

	FVector right = GetActorRightVector().GetSafeNormal();
	AddMovementInput(right, speed * value);
}

void AMyPlayer::Turn(float value) {

	AddControllerYawInput(value * rotationSpeed);
}

void AMyPlayer::LookUp(float value) {

	AddControllerPitchInput(value * lookUpSpeed);
}

void AMyPlayer::Shoot() {

	GetWorld()->SpawnActor<ABulletProjectile>(bulletPrefab, GetActorLocation(), GetActorRotation());
}
