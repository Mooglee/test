// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_DmgCalc_Core.h"
#include "Kismet/KismetMathLibrary.h"
#include "Mob_DmgCalc_PhysicalAttack.generated.h"


UCLASS()
class UMob_DmgCalc_PhysicalAttack : public UMob_DmgCalc_Core
{
	GENERATED_UCLASS_BODY()

		void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;
	
};
