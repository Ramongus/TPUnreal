// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WeaponAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class TPUNREAL_API UWeaponAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool isShooting;

public:
	UFUNCTION(BlueprintCallable)
		void ChangeShootingValue();

};
