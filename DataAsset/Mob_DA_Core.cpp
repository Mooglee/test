// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_DA_Core.h"



EDataValidationResult UMob_DA_Core::IsDataValid(TArray<FText>& ValidationErrors)
{
	if(Image)
	{
		return EDataValidationResult::Valid;
	}
	else {
		return EDataValidationResult::Invalid;
	}
	//return EDataValidationResult::NotValidated;
}
