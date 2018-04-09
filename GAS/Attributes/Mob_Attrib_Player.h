// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Mob_Attrib_Player.generated.h"

/**
 * 
 */
UCLASS()
class UMob_Attrib_Player : public UAttributeSet
{
	GENERATED_BODY()
	
public:
		UPROPERTY(Category = "Player", EditAnywhere, BlueprintReadWrite)
		float Exp;
	UPROPERTY(Category = "Player", EditAnywhere, BlueprintReadWrite)
		float Gold;
	UPROPERTY(Category = "Player", EditAnywhere, BlueprintReadWrite)
		float DropRate;
	
};
