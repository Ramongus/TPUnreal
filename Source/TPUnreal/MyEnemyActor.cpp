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
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &AMyEnemyActor::Shoot, timeBetweenShoot, true, 0.f);

	auto mesh = FindComponentByClass<USkeletalMeshComponent>();
	if (mesh)
	{
		animatorEnemy = Cast<UEnemy_AnimIns>(mesh->GetAnimInstance());
	}

	TArray<AActor*> pawnActors;
	UGameplayStatics::GetAllActorsOfClass(this, AMyPlayer::StaticClass(), pawnActors);


	theplayer = pawnActors[0];


	currentLife = totalLife;

	canRotate = true;
	canMove = true;
	canShoot = true;
	died = false;

	audioComp = FindComponentByClass<UAudioComponent>();
}

// Called every frame
void AMyEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (canMove == true)
	{
		AMyEnemyActor::MoveForward();
	}

	if (currentLife <= 0 && !died)
	{
		DieAction();
	}

	AMyEnemyActor::CheckIdle();

	FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), theplayer->GetActorLocation());

	lookRotation = FRotator(0, lookRotation.Yaw, 0);

	if (canRotate)
		SetActorRotation(lookRotation, ETeleportType::None);

}

void AMyEnemyActor::CheckIdle()
{
	float dis = FMath::Abs(FVector::Dist(theplayer->GetActorLocation(), GetActorLocation()));
	if (dis <= distanceToStop)
	{
		canMove = false;
		animatorEnemy->ChangeIsWalkingValue(false);
	}
	else
	{
		canMove = true;
	}

}

void AMyEnemyActor::MoveForward()
{
	animatorEnemy->ShootNotify(false);
	FVector dirVector = theplayer->GetActorLocation() - GetActorLocation();
	dirVector = FVector(dirVector.X, dirVector.Y, 0);
	SetActorLocation(GetActorLocation() + dirVector.GetSafeNormal() * speed);
	animatorEnemy->ChangeIsWalkingValue(true);
}

void AMyEnemyActor::Shoot()
{	
	if (canShoot)
	{
		animatorEnemy->ShootNotify(false);

		if (audioComp)
		{
			audioComp->Stop();
			if (shootSound)
			{
				audioComp->SetSound(shootSound);
				audioComp->Play();
			}
		}
		
		if (bulletPrefab && canMove == false)
		{
			FVector spawnPos = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 70);
			GetWorld()->SpawnActor<ABulletProjectile>(bulletPrefab, spawnPos + (GetActorLocation().ForwardVector*90), GetActorRotation());
		}
		animatorEnemy->ShootNotify(true);
	}
}

void AMyEnemyActor::TakeDamage(int damage)
{
	currentLife -= damage;
}

void AMyEnemyActor::DieAction()
{
	died = true;
	currentLife = 0;
	canMove = false;
	canShoot = false;
	canRotate = false;
	animatorEnemy->DieNotify();
}
