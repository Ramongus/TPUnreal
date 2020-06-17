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

	if (pawnActors[0] != nullptr)
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

	if (theplayer == nullptr)
	{
		TArray<AActor*> pawnActors;
		UGameplayStatics::GetAllActorsOfClass(this, AMyPlayer::StaticClass(), pawnActors);

		if (pawnActors[0] != nullptr)
			theplayer = pawnActors[0];
		return;
	}


	if (died == true)
	{
		timeToDie -= DeltaTime;
		if (timeToDie <= 0)
		{
			if (lifes > 1)
			{
				TArray<AActor*> spawnActors;
				UGameplayStatics::GetAllActorsOfClass(this, ASpawnPoint::StaticClass(), spawnActors);

				if (spawnActors[0] != nullptr)
				{
					SetActorLocation(spawnActors[FMath::RandRange(0, 4)]->GetActorLocation());
				}
				lifes--;
				timeToDie = 3;
				currentLife = totalLife;
				died = false;
				canMove = true;
				canShoot = true;
				canRotate = true;
				if (myUserWidget)
				{
					myUserWidget->UpdateLifeBar(currentLife, totalLife);
				}
				animatorEnemy->DieNotify(false);
			}
			else
			{
				ATPUnrealGameState* myState = GetWorld()->GetGameState<ATPUnrealGameState>();
				if (myState)
				{
					myState->AddDestroyedEnemy();
				}
				DestroyThisObject();
			}
		}
		return;
	}

	if (canMove == true)
	{
		AMyEnemyActor::MoveForward();
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
		if(!died) canMove = true;
	}

}

void AMyEnemyActor::DestroyThisObject()
{
	Destroy();
}

void AMyEnemyActor::MoveForward()
{
	if (audioComp)
	{
		audioComp->Stop();
	}
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

		

		if (bulletPrefab && canMove == false)
		{

			FRotator shootRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), theplayer->GetActorLocation());

		


			PlaySound(shootSound);
			FVector spawnPos = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 70);
			GetWorld()->SpawnActor<ABulletProjectile>(bulletPrefab, spawnPos + (GetActorForwardVector() * 90), shootRotation);
		}
		animatorEnemy->ShootNotify(true);
	}
}



void AMyEnemyActor::TakeDamage(int damage,int points)
{
	if (died) return;
	currentLife -= damage;
	ATPUnrealGameState* myState = GetWorld()->GetGameState<ATPUnrealGameState>();
	PlaySound(hitSound);
	animatorEnemy->HitNotify(true);
	if (myState)
	{
		myState->SetScore(points);
	}
	if (myUserWidget)
	{
		myUserWidget->UpdateLifeBar(currentLife, totalLife);
	}
	if (currentLife <= 0 && !died)
	{
		DieAction();
	}
	
}

void AMyEnemyActor::DieAction()
{
	ATPUnrealGameState* myState = GetWorld()->GetGameState<ATPUnrealGameState>();
	if (myState)
	{
		myState->SetScore(10);
	}
	PlaySound(deathSound);
	died = true;
	currentLife = 0;
	canMove = false;
	canShoot = false;
	canRotate = false;
	animatorEnemy->DieNotify(true);
}

void AMyEnemyActor::PlaySound(USoundCue* sound)
{
	if (audioComp)
	{
		audioComp->Stop();
		if (sound)
		{
			audioComp->SetSound(sound);
			audioComp->Play();
		}
	}
}