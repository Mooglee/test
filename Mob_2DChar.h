// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "GameplayAbilitySpec.h"
#include "DataAsset/Mob_DA_Item.h"
#include "DataAsset/Mob_DA_TalentTree.h"
#include "DataAsset/Mob_Struct_ItemWrapper.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "Structs/Mob_Struct_StatsHolder.h"

#include "Mob_2DChar.generated.h"


class UInputComponent;
class UPawnMovementComponent;

UCLASS()
class AMob_2DChar : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

		// override ////////// Movement
	virtual UPawnMovementComponent* GetMovementComponent() const override;
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;
	virtual void UpdateNavigationRelevance() override;
	//
	UFUNCTION(BlueprintCallable, Category = "Pawn")
		virtual void MoveForward(float Val);

	UFUNCTION(BlueprintCallable, Category = "Pawn")
		virtual void MoveRight(float Val);

	UFUNCTION(BlueprintCallable, Category = "Pawn")
		virtual void MoveUp_World(float Val);
	//////////////////////////// movement

public:
	
	AMob_2DChar();
	// GPA
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystem;
	UAbilitySystemComponent* GetAbilitySystemComponent() const override //We add this function, overriding it from IAbilitySystemInterface.
	{
		return AbilitySystem;
	};
	//

	//temp

	UMob_DA_TalentTree* TempTree = LoadObject<UMob_DA_TalentTree>(nullptr, TEXT("/Game/Paper2d/Core/Player/Talents/Warrior_Power/DA_TT_WarPower.DA_TT_WarPower"));

	//equipment
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Equipment;

	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Equipment_Bag;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Usable_Bag;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere, Category = "Bags")
		TArray<FStruct_ItemWrapper> Crafting_Bag;

	// equipment end


	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* CollisionComponent;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		UPaperFlipbookComponent* Sprite;
	
	UPROPERTY(Category = Talents, EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer OwnedTalents;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
		bool InCombat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Progression")
		int32 Gold;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Progression")
		int32 Exp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Progression")
		int32 Level;
	

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

	////////////// functions
	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
		void FloatingCombatText(float Amount, EEnum_CombatTextTarget Target, EEnum_CombatTextType Type, EEnum_CombatTextImpact ImpactType, AActor* SourceActor, AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category = "Talents")
		void ApplyStatsToGPE(TSubclassOf<UGameplayEffect> GPE, FStruct_StatsHolder Stats);

	UFUNCTION(BlueprintCallable, Category = "Talents")
		void ApplyTalentChanges(FStruct_StatsHolder& Stats);
	UFUNCTION(BlueprintCallable, Category = "Talents")
		void ApplyStatChanges(FStruct_StatsHolder& Stats);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		virtual void GiveAbility(TSubclassOf<class UGameplayAbility> AbilityGiven, int32 ID, FGameplayAbilitySpecHandle &AbilityHandle);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		virtual void ClearAbility(FGameplayAbilitySpecHandle AbilityRemoved);
	UFUNCTION(BlueprintCallable, Category = "Abilities")
		virtual void ClearAllAbilities();
		
	/** If true, adds default input bindings for movement and camera look. */
	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadOnly)
		uint32 bAddDefaultMovementBindings : 1;

	/** Name of the CollisionComponent. */
	static FName CollisionComponentName;

	/** Name of the MovementComponent.  Use this name if you want to use a different class (with ObjectInitializer.SetDefaultSubobjectClass). */
	static FName MovementComponentName;

private:

		UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UPawnMovementComponent* MovementComponent;

};
