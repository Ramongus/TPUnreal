// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_AnimIns.h"

void UEnemy_AnimIns::ChangeIsWalkingValue(bool value)
{
	isWalking = value;
}

void UEnemy_AnimIns::ShootNotify(bool value)
{
	isShooting = value;
}

void UEnemy_AnimIns::DieNotify()
{
	died = true;
}