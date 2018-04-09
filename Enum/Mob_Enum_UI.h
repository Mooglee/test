// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)		//Number type
enum class EEnum_SlotState : uint8
{
	Non 	UMETA(DisplayName = "non"),
	EquipNormal 	UMETA(DisplayName = "Equipment Normal"),
	EquipSelected 	UMETA(DisplayName = "Equipment Selected"),
	TalentNormal	UMETA(DisplayName = "Talent Normal"),
	TalentSelect	UMETA(DisplayName = "Talent Selected")
};
