#pragma once
//#include "PaperExpandedPlugin.h"
#include "Paper2DClasses.h"
#include "Mob_TileData.generated.h"

/**
*
*/
UCLASS(ClassGroup = (Paper2D), Blueprintable)
class UMob_TileData : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Tile Blueprints")
		UPaperTileSet* TileSet;

	UPROPERTY(EditAnywhere, Category = "Tile Blueprints")
		bool Replace;

	UPROPERTY(EditAnywhere, Category = "Tile Blueprints")
		TMap<int32, TSubclassOf<AActor>> Blueprints;

};