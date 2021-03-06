// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Mob_TileData.h"
#include "Mob_2dStructs.generated.h"

/*
X: X position in tilemap
Y: Y position in tilemap
layerIndex: Layer that the tile is on
info: the Tile Info this tile has
*/
USTRUCT()
struct FPaperTilePrefab
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY()
		int32 X;

	UPROPERTY()
		int32 Y;

	UPROPERTY()
		int32 LayerIndex;

	UPROPERTY()
		FPaperTileInfo Info;

	UPROPERTY()
		UPaperTileSet* TileSet;

	UPROPERTY()
		UMob_TileData* DataSet;

	
};

USTRUCT(BlueprintType)
struct FPaperTilePosition
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Layer;
};

UENUM(BlueprintType)
enum class EUpAxis : uint8
{
	UA_Y	UMETA(DisplayName = "Y Axis"),
	UA_Z	UMETA(DisplayName = "Z Axis")
};