// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_DmgCalc_Core.h"
#include "../Private/Mob_2DChar.h"
//#include "AbilitySystemComponent.h"




void UMob_DmgCalc_Core::SpawnFloatingCombatText(float Amount, EEnum_CombatTextTarget Target, EEnum_CombatTextType Type, EEnum_CombatTextImpact ImpactType, AActor* SourceActor, AActor* TargetActor) const
{

	AMob_2DChar* Char = Cast<AMob_2DChar>(SourceActor);
	if (Char != nullptr)
	{
		Char->FloatingCombatText(Amount, Target, Type, ImpactType, SourceActor, TargetActor);
	}
	else {

		AMob_2DChar* Char = Cast<AMob_2DChar>(TargetActor);
		if (Char != nullptr)
		{
			Char->FloatingCombatText(Amount, EEnum_CombatTextTarget::Player, Type, ImpactType, TargetActor, SourceActor);
		}

	}

}