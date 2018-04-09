// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


UENUM(BlueprintType)		//Number type
enum class EEnum_CombatTextType : uint8
{
	Non 	UMETA(DisplayName = "non"),
	Damage 	UMETA(DisplayName = "Damage"),
	Heal 	UMETA(DisplayName = "Heal"),
	Buff	UMETA(DisplayName = "Buff"),
	Debuff	UMETA(DisplayName = "Debuff")
};

UENUM(BlueprintType)		//impact type
enum class EEnum_CombatTextImpact : uint8
{
	Non 	UMETA(DisplayName = "non"),
	Miss 	UMETA(DisplayName = "Miss"),
	Crit 	UMETA(DisplayName = "Crit"),
	Block 	UMETA(DisplayName = "Block")
};

UENUM(BlueprintType)
enum class EEnum_CombatTextTarget : uint8 // target
{
	Non 	UMETA(DisplayName = "non"),
	Player 	UMETA(DisplayName = "Player"),
	Target 	UMETA(DisplayName = "Target")
};
