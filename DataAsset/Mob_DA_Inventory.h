// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_DA_Core.h"
#include "Mob_DA_Inventory.generated.h"


UENUM(BlueprintType) 
enum class EEnum_ItemType : uint8
{
	Non UMETA(DisplayName = "Non"),
	Equipment UMETA(DisplayName="Equipment"),
	Usable UMETA(DisplayName = "Usable"),
	Crafting UMETA(DisplayName = "Crafting")
};

UCLASS(Blueprintable, BlueprintType)
class UMob_DA_Inventory : public UMob_DA_Core
{
	GENERATED_BODY()
	
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = bChecks)
		bool KeyItem;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = bChecks)
		bool Sellable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = bChecks)
		bool Buyable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = bChecks)
		bool Usable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = bChecks)
		bool CanStack;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = bChecks)
		int StackLimit;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Type)
		EEnum_ItemType ItemType;

};
