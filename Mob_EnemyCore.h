// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Mob_InteractiveActor.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "GameplayAbilitySpec.h"
#include "AbilitySystemComponent.h"
#include "Mob_EnemyCore.generated.h"

UCLASS()
class AMob_EnemyCore : public AMob_InteractiveActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMob_EnemyCore();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
		bool IsEnemy;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystem;
	UAbilitySystemComponent* GetAbilitySystemComponent() const override //We add this function, overriding it from IAbilitySystemInterface.
	{
		return AbilitySystem;
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
