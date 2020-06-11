// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyGenerator.h"

// Sets default values for this component's properties
UEnemyGenerator::UEnemyGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyGenerator::BeginPlay()
{
	Super::BeginPlay();
	

	TArray<AActor*> spawnActors;
	UGameplayStatics::GetAllActorsOfClass(this, ASpawnPoint::StaticClass(), spawnActors);

	if (spawnActors[0] != nullptr)
	{
		spawnPoints = spawnActors;
		SpawnPlayers();
	}
	

	// ...

}


// Called every frame
void UEnemyGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemyGenerator::SpawnPlayers()
{
	for (int i = 0; i < enemiesToSpawn; i++)
	{
		GetWorld()->SpawnActor<AMyEnemyActor>(EnemyPrefab, spawnPoints[FMath::RandRange(0, spawnPoints.Num())]->GetActorLocation(), spawnPoints[0]->GetActorRotation());

	}
}

