// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Private/DataAsset/Mob_DA_Item.h"
#include "Mob_Struct_ItemWrapper.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FStruct_ItemWrapper
{
	GENERATED_USTRUCT_BODY()



		UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		UMob_DA_Equipment* item;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		bool Cursed;


	FStruct_ItemWrapper()
	{
	}

};