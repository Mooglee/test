// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Mob_DA_Talent.h"
#include "GameplayTagContainer.h"
#include "Mob_DA_TalentTree.generated.h"

struct FGameplayTagContainer;

USTRUCT(BlueprintType)
struct FStruct_XY
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int32 X;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int32 Y;

	FStruct_XY()
	{
		X = 0;
		Y = 0;
	}

};


USTRUCT(BlueprintType)
struct FStruct_Talent
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FStruct_XY GridLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FGameplayTag TalentTag;

	UPROPERTY( BlueprintReadWrite, EditAnywhere)
		FGameplayTagContainer RequiredTalents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FGameplayTagContainer TalentsThatBlockThisTalent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 RequiredPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMob_DA_Talent* Talent;

		FStruct_Talent()
	{

	}

};

/**
 * 
 */


struct FGameplayTagContainer;
UCLASS(Blueprintable, BlueprintType)
class UMob_DA_TalentTree : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FStruct_Talent> TalentList;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = aGeneral)
		FName TreeName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = aGeneral)
		FText TreeDesc;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = aGeneral)
		UTexture2D* TreeIcon;
};
