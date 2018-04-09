// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Mob_DA_Enemy.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UMob_DA_Enemy : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation)
		class UPaperFlipbook* Idle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation)
		class UPaperFlipbook* Attack;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		int32 GoldDrop;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		int32 ExpDrop;


	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float HealthMax;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float ManaMax;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float EnergyMax;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DamagePhysical;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DamageMagical;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DefensePhysical;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float DefenseMagical;

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

	
	
};
