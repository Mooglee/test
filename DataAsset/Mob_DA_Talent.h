// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_DA_Core.h"
#include "../Private/Enum/Mob_Enum_Player.h"
#include "Mob_DA_Talent.generated.h"





UCLASS()
class UMob_DA_Talent : public UMob_DA_Core
{
	GENERATED_BODY()
		// Stats
public:


	UPROPERTY(Category = "Weapon", EditAnywhere, BlueprintReadWrite)
		EEnum_WeaponTypes WeaponDamageModifier;
	UPROPERTY(Category = "Weapon", EditAnywhere, BlueprintReadWrite)
		int32 WeaponDamageModifierIncreasePercent;

	UPROPERTY(Category = "TalentType", EditAnywhere, BlueprintReadWrite)
		int32 Steps;
	UPROPERTY(Category = "TalentType", EditAnywhere, BlueprintReadWrite)
		float StepModifier;
	UPROPERTY(Category = "TalentType", EditAnywhere, BlueprintReadWrite)
		float StepFinalAddition;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float HealthMax;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float HealthRegen;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float ManaMax;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float ManaRegen;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float EnergyMax;
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
		float Exp;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float Gold;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DropRate;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float AttackSpeedModifier;

	// attributes

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Mana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Energy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Strength;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Intelligence;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Vigor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Spirit;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Agility;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Luck;


};
