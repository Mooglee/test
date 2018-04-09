// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_EnemyCore.h"


// Sets default values
AMob_EnemyCore::AMob_EnemyCore()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
}

// Called when the game starts or when spawned
void AMob_EnemyCore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMob_EnemyCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

