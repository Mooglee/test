// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_Map.h"


// Sets default values
AMob_Map::AMob_Map()
{
	TileMap = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMap"));
	//TileMap->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMob_Map::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMob_Map::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMob_Map::ScanTilesForCollison()
{
	int32 TileWidth = 0;
	int32 Tileheight = 0;
	int32 Layers = 0;
	TileMap->GetMapSize(TileWidth, Tileheight, Layers);

	// temp variables for loop
	int32 Width = 0;
	int32 Height = 0;
	//UE_LOG(LogTemp, Warning, TEXT("Setup"));
	for (int32 count = (TileWidth * Tileheight); count > 0; --count)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Doing Logic %d"), count);
		// do logic
		if (TileLayersHasCol(Width, Height, Layers))
		{

		}
		else // if no col add to empty tiles
		{
			FStruct_TileMetaData TempData;
			TempData.X = Width;
			TempData.Y = Height;
			EmptyTiles.Add(TempData);
			UE_LOG(LogTemp, Warning, TEXT("Tiles added X: %d Y: %d"), TempData.X, TempData.Y);
		}

		//then do me
		if (Width == TileWidth-1)
		{
			Width = 0;
			Height++;
		}
		else
		{
			Width++;
		}

	}

}

void AMob_Map::FindEmptyRandomTile(int& X, int& Y)
{
	int32 TileWidth = 0;
	int32 Tileheight = 0;
	int32 Layers = 0;
	TileMap->GetMapSize(TileWidth, Tileheight, Layers);
	TileWidth--;
	Tileheight--;

	int32 RandomX = 0;
	int32 RandomY = 0;
	for (int32 count=(TileWidth * Tileheight); count > 0; --count)
	{
		RandomX = FMath::RandRange(0, TileWidth);
		RandomY = FMath::RandRange(0, Tileheight);

		if(TileLayersHasCol(RandomX, RandomY, Layers))
		{
			RandomX = -1;
			RandomY = -1;

		} else
		{
			X = RandomX;
			Y = RandomY;
			count = 0;
		}
		
	}

}

bool AMob_Map::TileLayersHasCol(int32 RandomX, int32 RandomY, int32 Layers)
{
	FPaperTileInfo Tile;
	bool LayerHasCollison = false; 
	for (int i = Layers-1; i >= 0; --i)
	{
		Tile = (TileMap->GetTile(RandomX, RandomY, i));
		if (TileHasCollison(Tile.GetTileIndex(), Tile.TileSet))
		{
			LayerHasCollison = true;
		}
	}

	return(LayerHasCollison);
}

bool AMob_Map::TileHasCollison(int32 TileIndex, const UPaperTileSet* TileSet)
{
	
	if (TileSet && TileIndex != INDEX_NONE)
	{
		const FPaperTileMetadata* const Metadata = TileSet->GetTileMetadata(TileIndex);
		//UE_LOG(LogTemp, Warning, TEXT("Checking a tile for Col"));
		return Metadata ? Metadata->HasCollision() : false;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Warning no tile"));
		return(false);
	}
}