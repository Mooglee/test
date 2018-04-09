// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Mob_DA_Enemy.h"
#include "Mob_DA_Item.h"
#include "Mob_DA_FloorContent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UMob_DA_FloorContent : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, BlueprintType, EditInstanceOnly, Category = "Enemies")
		TArray<UMob_DA_Enemy*> Enemies;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditInstanceOnly, Category = "Enemies")
		int32 MinSpawn;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditInstanceOnly, Category = "Enemies")
		int32 MaxSpawn;
	
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditInstanceOnly, Category = "Drops")
		TArray<UMob_DA_Item*> Equipment;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditInstanceOnly, Category = "Drops")
		TArray<UMob_DA_Item*> Usable;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditInstanceOnly, Category = "Drops")
		TArray<UMob_DA_Item*> Crafting;
};
