// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_DmgCalc_PhysicalAttack.h"
#include "../Private/GAS/Attributes/Mob_Attrib_Stats.h"
#include "AbilitySystemComponent.h"


struct DmgStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(HealthCurrent);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamagePhysical);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePhysical);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Evasion);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Accuracy);
	DECLARE_ATTRIBUTE_CAPTUREDEF(CritRate);
	DECLARE_ATTRIBUTE_CAPTUREDEF(CritDamage);


	DmgStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, HealthCurrent, Target, false); // get target hp
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, DamagePhysical, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, DefensePhysical, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, Evasion, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, Accuracy, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, CritRate, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMob_Attrib_Stats, CritDamage, Source, false);
	}
};

DmgStatics& stats()
{
	static DmgStatics It;
	return It;
}


UMob_DmgCalc_PhysicalAttack::UMob_DmgCalc_PhysicalAttack(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RelevantAttributesToCapture.Add(stats().HealthCurrentDef);
	RelevantAttributesToCapture.Add(stats().DamagePhysicalDef);
	RelevantAttributesToCapture.Add(stats().DefensePhysicalDef);
	RelevantAttributesToCapture.Add(stats().EvasionDef);
	RelevantAttributesToCapture.Add(stats().AccuracyDef);
	RelevantAttributesToCapture.Add(stats().CritRateDef);
	RelevantAttributesToCapture.Add(stats().CritDamageDef);
}

void UMob_DmgCalc_PhysicalAttack::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{

	UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->AvatarActor : nullptr;
	AActor* TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->AvatarActor : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluationParameters;
	/////////////////

	float Health = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().HealthCurrentDef, EvaluationParameters, Health);
	float DamagePhysical = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().DamagePhysicalDef, EvaluationParameters, DamagePhysical);
	float DefensePhysical = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().DefensePhysicalDef, EvaluationParameters, DefensePhysical);
	float Evasion = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().EvasionDef, EvaluationParameters, Evasion);
	float Accuracy = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().AccuracyDef, EvaluationParameters, Accuracy);
	float CritRate = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().CritRateDef, EvaluationParameters, CritRate);
	float CritDmg = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(stats().CritDamageDef, EvaluationParameters, CritDmg);
	bool Crit = false;

	Accuracy = Accuracy + 90;
	Accuracy = ((Accuracy - Evasion) / 100);
	
	
	if (UKismetMathLibrary::RandomBoolWithWeight(Accuracy))
	{
		
		CritRate = CritRate / 100;
		if (UKismetMathLibrary::RandomBoolWithWeight(CritRate))
		{
			CritDmg = CritDmg / 100;
			CritDmg = CritDmg + 1;
			DamagePhysical = (DamagePhysical * CritDmg);
			Crit = true;
		}

		DamagePhysical = DamagePhysical - DefensePhysical;
		DamagePhysical = FMath::Clamp(DamagePhysical, 0.f, 999999.f);

	}
	else {

		DamagePhysical = 0;
	}
	
	SpawnFloatingCombatText(DamagePhysical, EEnum_CombatTextTarget::Target, EEnum_CombatTextType::Damage, EEnum_CombatTextImpact::Non, SourceActor, TargetActor);

	UE_LOG(LogTemp, Warning, TEXT("Damage done : %f did it crit?: %s"), DamagePhysical, (Crit ? TEXT("true") : TEXT("False")));

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(stats().HealthCurrentProperty, EGameplayModOp::Additive, -DamagePhysical));
	
}