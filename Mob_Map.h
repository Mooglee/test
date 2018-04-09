// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileMapComponent.h"
#include "PaperTileSet.h"
#include "Mob_Map.generated.h"

USTRUCT(BlueprintType)
struct FStruct_TileMetaData
{
	GENERATED_USTRUCT_BODY()
public:
		UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int X;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintType)
		int Y;


		FStruct_TileMetaData()
		{
			X = 0;
			Y = 0;
		}
};

UCLASS()
class AMob_Map : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMob_Map();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Variables!
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UPaperTileMapComponent* TileMap;
	UPROPERTY(BlueprintReadWrite, BlueprintType, EditAnywhere)
		TArray<FStruct_TileMetaData> EmptyTiles;
	//////////////
	
	// FUNCTIONS!
	UFUNCTION(BlueprintCallable)
		void FindEmptyRandomTile(int& X, int& Y);

	UFUNCTION(BlueprintCallable)
		void ScanTilesForCollison();

	bool TileLayersHasCol(int32 RandomX, int32 RandomY, int32 Layers);
	bool TileHasCollison(int32 TileIndex, const UPaperTileSet* TileSet);
	///////////////
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
