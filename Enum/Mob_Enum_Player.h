// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



UENUM(BlueprintType)		//Number type
enum class EEnum_ButtonType : uint8
{
	Non 	UMETA(DisplayName = "non"),
	Equipment 	UMETA(DisplayName = "Equipment"),
	Bags 	UMETA(DisplayName = "Bags"),
	ActionBar	UMETA(DisplayName = "Action Bar")
};

UENUM(BlueprintType)
enum class EEnum_AttributeGainType : uint8 // target
{
	Non 	UMETA(DisplayName = "non"),
	LevelUp UMETA(DisplayName = "Level Up"),
	Item 	UMETA(DisplayName = "Item"),
	Respec 	UMETA(DisplayName = "Respec")
};

UENUM(BlueprintType)
enum class EEnum_AttributeType : uint8 // target
{
	Non 	UMETA(DisplayName = "non"),
	Health 	UMETA(DisplayName = "Health"),
	Mana 	UMETA(DisplayName = "Mana"),
	Energy 	UMETA(DisplayName = "Energy"),
	Strength 	UMETA(DisplayName = "Strength"),
	intelligence 	UMETA(DisplayName = "intelligence"),
	Vigor 	UMETA(DisplayName = "Vigor"),
	Spirit 	UMETA(DisplayName = "Spirit"),
	Agility 	UMETA(DisplayName = "Agility"),
	Luck 	UMETA(DisplayName = "Luck")
};

UENUM(BlueprintType)
enum class EEnum_WeaponTypes : uint8
{
	Non 	UMETA(DisplayName = "Non"),
	Sword 	UMETA(DisplayName = "Sword"),
	Axe 	UMETA(DisplayName = "Axe"),
	Mace 	UMETA(DisplayName = "Mace"), // Maybe?
	Spear	UMETA(DisplayName = "Spear"),
	Dagger 	UMETA(DisplayName = "Dagger"),
	Bow 	UMETA(DisplayName = "Bow"),
	Whip 	UMETA(DisplayName = "Whip"), // maybe?
	Book 	UMETA(DisplayName = "Book"),
	Staff	UMETA(DisplayName = "Staff"),
	Throw	UMETA(DisplayName = "Throwing") // maybe?
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EEnum_EquipSlot : uint8
{
	Non 	UMETA(DisplayName = "Non"),
	Head 	UMETA(DisplayName = "Head"),
	Chest 	UMETA(DisplayName = "Chest"),
	Legs 	UMETA(DisplayName = "Legs"),
	Hands 	UMETA(DisplayName = "Hands"),
	Feet	UMETA(DisplayName = "Feet"),
	MainHand 	UMETA(DisplayName = "Main Hand"),
	OffHand 	UMETA(DisplayName = "Off Hand"),
	Ring 	UMETA(DisplayName = "Ring"),
	Neck 	UMETA(DisplayName = "Neck"),
	Relic 	UMETA(DisplayName = "Relic")
};