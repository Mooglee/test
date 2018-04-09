// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_Struct_statsHolder.generated.h"


USTRUCT(BlueprintType)
struct FStruct_StatsHolder
{
	GENERATED_USTRUCT_BODY()

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


		FStruct_StatsHolder()
	{
			HealthMax = 0;
			HealthRegen = 0;

			ManaMax = 0;
			ManaRegen = 0;

			 EnergyMax = 0;
			 EnergyRegen = 0;
	
			 DamagePhysical = 0;
			 DamageMagical = 0;

			
			 DefensePhysical = 0;
			 DefenseMagical = 0;


			 BlockChance = 0;
			 BlockDamage = 0;

	
			Accuracy = 0;
			Evasion = 0;

			CritRate = 0;
			CritDamage = 0;

			DamageBleed = 0;
			DamagePoison = 0;

			StealHealth = 0;
			StealMana = 0;
			StealEnergy = 0;

			
			 Exp = 0;
			 Gold = 0;
			 DropRate = 0;

			AttackSpeed = 0;
			AttackSpeedModifier = 0;

	}

};