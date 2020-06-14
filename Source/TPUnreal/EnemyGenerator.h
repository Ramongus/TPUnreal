// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "MyEnemyActor.h"
#include "SpawnPoint.h"
#include "Components/ActorComponent.h"
#include "EnemyGenerator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPUNREAL_API UEnemyGenerator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyGenerator();

	
	int enemiesToSpawn = 2;
	int timeToSpawnEnemies = 5;
	float spawnTimer;
	UPROPERTY(EditAnywhere)
	TArray<AActor*> spawnPoints;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AMyEnemyActor> EnemyPrefab;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SpawnPlayers();
		
};
