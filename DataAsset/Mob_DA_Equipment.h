// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_DA_Inventory.h"
#include "../Private/Enum/Mob_Enum_Player.h"
#include "Mob_DA_Equipment.generated.h"






UCLASS(Blueprintable, BlueprintType)
class UMob_DA_Equipment : public UMob_DA_Inventory
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Type)
		EEnum_EquipSlot Slot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Type)
		EEnum_WeaponTypes WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Type)
		bool Is2H;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Type)
		bool dual;

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
};
