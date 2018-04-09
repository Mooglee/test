// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "../Private/Enum/Mob_Enum_CombatText.h"
#include "Mob_DmgCalc_Core.generated.h"


/**
 * 
 */
UCLASS()
class UMob_DmgCalc_Core : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:


	void SpawnFloatingCombatText(float Amount, EEnum_CombatTextTarget Target, EEnum_CombatTextType Type, EEnum_CombatTextImpact ImpactType, AActor* SourceActor, AActor* TargetActor) const;
	

	
};
