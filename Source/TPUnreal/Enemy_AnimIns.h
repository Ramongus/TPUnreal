// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Enemy_AnimIns.generated.h"

/**
 * 
 */
UCLASS()
class TPUNREAL_API UEnemy_AnimIns : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	bool isWalking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool isShooting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool died;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool gotHit;

public:
	UFUNCTION(BlueprintCallable)
		void ChangeIsWalkingValue(bool value);

	UFUNCTION(BlueprintCallable)
		void ShootNotify(bool value);

	UFUNCTION(BlueprintCallable)
		void DieNotify(bool value);
	UFUNCTION(BlueprintCallable)
		void HitNotify(bool value);
};
