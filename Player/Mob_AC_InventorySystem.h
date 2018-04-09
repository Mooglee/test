// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Private/DataAsset/Mob_Struct_ItemWrapper.h"
#include "Mob_AC_InventorySystem.generated.h"


UCLASS( ClassGroup=(Inventory), meta=(BlueprintSpawnableComponent), Blueprintable )
class UMob_AC_InventorySystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMob_AC_InventorySystem();

	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Equipment;

	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Equipment_Bag;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Usable_Bag;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Crafting_Bag;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
