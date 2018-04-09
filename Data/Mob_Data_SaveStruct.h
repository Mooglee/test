// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_Data_SaveStruct.generated.h"

USTRUCT(BlueprintType)
struct FStruct_SaveData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int32 Level;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int32 EXP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int32 Gold;

	//attributes
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
		int32 Unspent_Attributes;

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

	FStruct_SaveData()
	{

	}

};