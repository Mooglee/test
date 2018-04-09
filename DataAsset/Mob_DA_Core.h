// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Mob_DA_Core.generated.h"

/**
 * 
 */


UCLASS(Blueprintable, BlueprintType)
class UMob_DA_Core : public UDataAsset
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = aGeneral)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = aGeneral)
		FText Desc;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = aGeneral)
		UObject* Image;

	virtual EDataValidationResult IsDataValid(TArray<FText>& ValidationErrors) override;

};
