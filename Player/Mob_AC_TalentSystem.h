// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Mob_AC_TalentSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class UMob_AC_TalentSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMob_AC_TalentSystem();

	UPROPERTY(Category = Talents, EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer OwnedTalents;
	UPROPERTY(Category = Talents, EditAnywhere, BlueprintReadWrite)
		int32 TalentPoints;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
