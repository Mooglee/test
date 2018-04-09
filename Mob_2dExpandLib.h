// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob_2dStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Mob_2dExpandLib.generated.h"

/**
 * 
 */
UCLASS()
class UMob_2dExpandLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		/** Get Tile Position From Hit Location, useful for working with LineTrace. Supports 3D Collision Only*/
		UFUNCTION(BlueprintCallable, Category = "Paper2D")
		static FPaperTilePosition GetTilePositionFromHitLocation(EUpAxis axis, UPaperTileMapComponent * tilemapComp, FVector HitLocation, bool IgnoreCollisionThickness = false);

	/** Get Tile Paper Info From Hit Location, useful for working with LineTrace. Supports 3D Collision Only*/
	UFUNCTION(BlueprintCallable, Category = "Paper2D")
		static FPaperTileInfo GetTileFromHitLocation(EUpAxis axis, UPaperTileMapComponent * tilemapComp, FVector HitLocation, bool& TileFound);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Paper2D")
		static bool IsSocketOnFrame(const UPaperFlipbook* flipbook, FName socketName, const int32 frameIndex);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Paper2D")
		static bool TileHasCollison(int32 TileIndex, const UPaperTileSet* TileSet);
};
