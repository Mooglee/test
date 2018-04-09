// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_2dExpandLib.h"
#include "PaperTileSet.h"




FPaperTilePosition UMob_2dExpandLib::GetTilePositionFromHitLocation(EUpAxis axis, UPaperTileMapComponent * tilemapComp, FVector HitLocation, bool IgnoreCollisionThickness)
{
	float xSize, ySize, layerDif, collisionThickness;
	FVector relativeLocation = FVector();
	FPaperTilePosition tilePos = FPaperTilePosition();
	int32 tileWidth, tileHeight;

	if (tilemapComp != nullptr)
	{
		relativeLocation = HitLocation - tilemapComp->GetOwner()->GetActorLocation();

		tileHeight = tilemapComp->TileMap->TileHeight;
		tileWidth = tilemapComp->TileMap->TileWidth;

		xSize = tilemapComp->TileMap->PixelsPerUnrealUnit*tileWidth;
		ySize = tilemapComp->TileMap->PixelsPerUnrealUnit*tileHeight;

		collisionThickness = tilemapComp->TileMap->GetCollisionThickness();

		layerDif = tilemapComp->TileMap->SeparationPerLayer;
	}
	else
	{
		return FPaperTilePosition();
	}

	if (axis == EUpAxis::UA_Y)
	{
		tilePos.X = FMath::RoundToInt(FMath::Abs(relativeLocation.X / xSize));
		tilePos.Y = FMath::RoundToInt(FMath::Abs(relativeLocation.Y / ySize));

		if (!IgnoreCollisionThickness)
			relativeLocation.Z = FMath::Abs(relativeLocation.Z) - (collisionThickness / 2);

		tilePos.Layer = FMath::RoundToInt(FMath::Abs((relativeLocation.Z) / layerDif));
	}
	if (axis == EUpAxis::UA_Z)
	{
		tilePos.X = FMath::RoundToInt(FMath::Abs(relativeLocation.X / xSize));
		tilePos.Y = FMath::RoundToInt(FMath::Abs(relativeLocation.Z / ySize));

		if (!IgnoreCollisionThickness)
			relativeLocation.Y = FMath::Abs(relativeLocation.Y) - (collisionThickness / 2);

		tilePos.Layer = FMath::RoundToInt(FMath::Abs((relativeLocation.Y) / layerDif));
	}

	return tilePos;
}


FPaperTileInfo UMob_2dExpandLib::GetTileFromHitLocation(EUpAxis axis, UPaperTileMapComponent * tilemapComp, FVector WorldLocation, bool& TileFound)
{
	if (tilemapComp)
	{
		FPaperTilePosition tilePos = GetTilePositionFromHitLocation(axis, tilemapComp, WorldLocation);
		FPaperTileInfo info = tilemapComp->GetTile(tilePos.X, tilePos.Y, tilePos.Layer);
		TileFound = true;
		return info;
	}
	else
	{
		TileFound = false;
		FPaperTileInfo info1;
		return info1;
	}
}



bool UMob_2dExpandLib::IsSocketOnFrame(const UPaperFlipbook* flipbook, FName socketName, const int32 frameIndex)
{
	if (flipbook != nullptr && frameIndex <= (flipbook->GetNumFrames()))
	{
		if (flipbook->GetSpriteAtFrame(frameIndex)->FindSocket(socketName) != nullptr)
		{
			return true;
		}
	}

	return false;
}

bool UMob_2dExpandLib::TileHasCollison(int32 TileIndex, const UPaperTileSet* TileSet)
{
	check(TileSet);
	check(TileIndex != INDEX_NONE);

	const FPaperTileMetadata* const Metadata = TileSet->GetTileMetadata(TileIndex);
	return Metadata ? Metadata->HasCollision() : false;
}