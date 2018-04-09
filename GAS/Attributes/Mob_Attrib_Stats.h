// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Mob_Attrib_Stats.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_M_API UMob_Attrib_Stats : public UAttributeSet
{
	GENERATED_BODY()
public:


	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float HealthMax;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float HealthCurrent;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float HealthRegen;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float ManaMax;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float ManaCurrent;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float ManaRegen;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float EnergyMax;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float EnergyCurrent;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float EnergyRegen;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DamagePhysical;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DamageMagical;
	
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DefensePhysical;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DefenseMagical;


	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float BlockChance;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float BlockDamage;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float Accuracy;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float Evasion;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float CritRate;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float CritDamage;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DamageBleed;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DamagePoison;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float StealHealth;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float StealMana;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float StealEnergy;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float AttackSpeedModifier;
};
