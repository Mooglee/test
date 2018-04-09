// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Mob_Data_SaveStruct.h"

#include "../Private/DataAsset/Mob_Struct_ItemWrapper.h"

#include "Mob_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UMob_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere)
		FStruct_SaveData Player;
	
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Equipment;

	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Equipment_Bag;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Usable_Bag;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Crafting_Bag;
	
};
