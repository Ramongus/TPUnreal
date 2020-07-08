// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "PlayersHUD.h"
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

	burst = false;

	bulletSpawnPoint = Cast<USceneComponent>(refToSpawnBulletPoint.GetComponent(this));
	currentLife = totalLife;
	died = false;

	ATPUnrealGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATPUnrealGameModeBase>();
	//timesToDie = gameMode->playersLifes;
	timeToRespawn = gameMode->timeToSpawnPlayer;
	respawnTimer = 0;
	audioComp = FindComponentByClass<UAudioComponent>();

	myGI = Cast<UGameInstanceTPUnreal>(GetGameInstance());
	if (myGI)
	{
		ATPUnrealGameState* myGameState = GetWorld()->GetGameState<ATPUnrealGameState>();
		myGameState->SetScore(myGI->points);
		gameMode->myTimer = myGI->currentTime;
		timesToDie = myGI->playersLifes;
	}
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (hastoRestart) return;
	if (died)
	{
		ATPUnrealGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATPUnrealGameModeBase>();
		if (timesToDie < gameMode->playersLifes)
		{
			ATPUnrealGameState* myGameState = GetWorld()->GetGameState<ATPUnrealGameState>();
			myGameState->OnRoundDied();
			respawnTimer += DeltaTime;

			if (respawnTimer >= timeToRespawn)
			{
				auto player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
				if (player != nullptr)
				{
					SetActorLocation(player->GetSpawnLocation());
				}
				currentLife = totalLife;
				APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
				if (hud)	hud->UpdateLifeBar(currentLife, totalLife);
				died = false;
				respawnTimer = 0;
				timesToDie++;
				myGI->playersLifes = timesToDie;
			}
		}
		else
		{
			ATPUnrealGameState* myGameState = GetWorld()->GetGameState<ATPUnrealGameState>();
			myGameState->OnRoundLost();
			hastoRestart = true;
		}
	}

	UpdateTimer();
	
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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayer::JumpAction);
	PlayerInputComponent->BindAction("Restart", IE_Pressed, this, &AMyPlayer::RestartGame);
}

void AMyPlayer::MoveForward(float value) {

	if (!died)
	{
		FVector forward = GetActorForwardVector().GetSafeNormal();
		AddMovementInput(forward, speed * value);
	}
}

void AMyPlayer::MoveRight(float value) {
	if (!died)
	{
		FVector right = GetActorRightVector().GetSafeNormal();
		AddMovementInput(right, speed * value);
	}
}

void AMyPlayer::Turn(float value) {
	if (!died)
	{
		AddControllerYawInput(value * rotationSpeed);
	}
}

void AMyPlayer::LookUp(float value) {

	if (!died)
	{
		AddControllerPitchInput(value * lookUpSpeed);
	}
}

void AMyPlayer::Shoot() {

	if (!died)
	{
		if (!burst) {
			UE_LOG(LogTemp, Warning, TEXT("NoBurst"));
			CreateBullet();
		}
	}
}

void AMyPlayer::JumpAction()
{
	if (!died)
	{
		Jump();
	}
}

void AMyPlayer::TakeDamage(int damage)
{
	if (died) return;
	currentLife -= damage;
	PlaySound(hitSound);
	APlayersHUD* hud = Cast<APlayersHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (hud)	hud->UpdateLifeBar(currentLife, totalLife);
	else UE_LOG(LogTemp, Warning, TEXT("no hay hud"));

	if (currentLife <= 0 && !died)
	{
		DieAction();
	}
}

void AMyPlayer::DieAction()
{
	died = true;
	PlaySound(deathSound);
}

void AMyPlayer::RestartGame()
{
	if (hastoRestart)
	{
		myGI->currentTime = 0;
		myGI->playersLifes = 0;
		myGI->points = 0;
		UGameplayStatics::OpenLevel(this, FName("DemoLevel"));
	}
}

void AMyPlayer::PlaySound(USoundCue* sound)
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

void AMyPlayer::UpdateTimer()
{
	ATPUnrealGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATPUnrealGameModeBase>();
	if (gameMode)
	{
		myGI->currentTime = gameMode->myTimer;
	}
}

void AMyPlayer::FireBurst()
{
	burst = true;
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &AMyPlayer::UnActiveBurst, timeBurst, false, timeBurst);
	CreateBullet();
}

void AMyPlayer::UnActiveBurst()
{
	burst = false;
}

void AMyPlayer::CreateBullet()
{
	GetWorld()->SpawnActor<ABulletProjectile>(bulletPrefab, bulletSpawnPoint->GetComponentLocation(), bulletSpawnPoint->GetComponentRotation());
	weaponAnim->ChangeShootingValue();
	if (burst) {
		UE_LOG(LogTemp, Warning, TEXT("InBurst"));
		GetWorld()->GetTimerManager().SetTimer(otherTimer, this, &AMyPlayer::CreateBullet, fireRateInBurst, false, fireRateInBurst);
	}
}

void AMyPlayer::Slow()
{
	speed = speed * slowMultiplier;
	GetWorld()->GetTimerManager().SetTimer(slowTimer, this, &AMyPlayer::NormalSpeed, timeSlowed, false, timeSlowed);
}

void AMyPlayer::NormalSpeed()
{
	speed = speed / slowMultiplier;
}
