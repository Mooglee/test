// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_AC_TalentSystem.h"


// Sets default values for this component's properties
UMob_AC_TalentSystem::UMob_AC_TalentSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMob_AC_TalentSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMob_AC_TalentSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

