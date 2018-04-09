// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_InteractiveActor.h"


// Sets default values
AMob_InteractiveActor::AMob_InteractiveActor()
{

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetBoxExtent(FVector(8, 8, 8));
	BoxComponent->SetCollisionProfileName(TEXT("Pawn"));

	

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMob_InteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMob_InteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

