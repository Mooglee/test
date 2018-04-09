// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Mob_InteractiveActor.generated.h"


UENUM(BlueprintType)
enum class EEnum_TargetType : uint8 // target
{
	Non 	UMETA(DisplayName = "non"),
	Enemy 	UMETA(DisplayName = "Enemy"),
	NPC 	UMETA(DisplayName = "NPC"),
	Shop 	UMETA(DisplayName = "Shop"),
	Door 	UMETA(DisplayName = "Door"),
	Reward 	UMETA(DisplayName = "Reward"),
	Trap 	UMETA(DisplayName = "Trap"),
	PuzzlePiece 	UMETA(DisplayName = "PuzzlePiece")
};

UCLASS()
class AMob_InteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AMob_InteractiveActor();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEnum_TargetType Type;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	
	
};
