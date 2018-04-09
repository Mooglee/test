// Fill out your copyright notice in the Description page of Project Settings.

#include "Mob_2DChar.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerInput.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/FloatingPawnMovement.h"

FName AMob_2DChar::MovementComponentName(TEXT("MovementComponent0"));
FName AMob_2DChar::CollisionComponentName(TEXT("CollisionComponent0"));

AMob_2DChar::AMob_2DChar()
{
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(AMob_2DChar::CollisionComponentName);
	CollisionComponent->SetBoxExtent(FVector(8, 8, 8));
	CollisionComponent->SetCollisionProfileName(TEXT("Pawn"));

	RootComponent = CollisionComponent;

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(AMob_2DChar::MovementComponentName);
	MovementComponent->UpdatedComponent = CollisionComponent;


	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(CollisionComponent);


	bAddDefaultMovementBindings = false;

	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));

	// temp

}


void AMob_2DChar::GiveAbility(TSubclassOf<class UGameplayAbility> AbilityGiven, int32 ID, FGameplayAbilitySpecHandle &AbilityHandle)
{ // 
	if (HasAuthority() && AbilityGiven)
	{

		AbilityHandle = AbilitySystem->GiveAbility(FGameplayAbilitySpec(AbilityGiven.GetDefaultObject(), 1, ID));
	}
}


void AMob_2DChar::ClearAbility(FGameplayAbilitySpecHandle AbilityRemoved)
{
	if (HasAuthority())
	{
		AbilitySystem->ClearAbility(FGameplayAbilitySpecHandle(AbilityRemoved));
	}
}


void AMob_2DChar::ClearAllAbilities()
{
	if (HasAuthority())
	{
		AbilitySystem->ClearAllAbilities();
	}
}

///stats

void AMob_2DChar::ApplyTalentChanges(FStruct_StatsHolder& Stats, FGameplayTagContainer OwnedTalents)
{
	if (TempTree)
	{
		UE_LOG(LogTemp, Warning, TEXT("is valid"));

		FStruct_StatsHolder StatsContainer;

		for (int32 Index = 0; Index != TempTree->TalentList.Num(); ++Index) // for every talent add stats up
		{

			if (OwnedTalents.HasTag(TempTree->TalentList[Index].TalentTag)) // do we have this talent?
			{
				StatsContainer.HealthMax += TempTree->TalentList[Index].Talent->HealthMax;
				StatsContainer.HealthRegen += TempTree->TalentList[Index].Talent->HealthRegen;

				StatsContainer.ManaMax += TempTree->TalentList[Index].Talent->ManaMax;
				StatsContainer.ManaRegen += TempTree->TalentList[Index].Talent->ManaRegen;

				StatsContainer.EnergyMax += TempTree->TalentList[Index].Talent->EnergyMax;
				StatsContainer.EnergyRegen += TempTree->TalentList[Index].Talent->EnergyRegen;

				StatsContainer.DamagePhysical += TempTree->TalentList[Index].Talent->DamagePhysical;
				StatsContainer.DamageMagical += TempTree->TalentList[Index].Talent->DamageMagical;

				StatsContainer.DefensePhysical += TempTree->TalentList[Index].Talent->DefensePhysical;
				StatsContainer.DefenseMagical += TempTree->TalentList[Index].Talent->DefenseMagical;

				StatsContainer.BlockChance += TempTree->TalentList[Index].Talent->BlockChance;
				StatsContainer.BlockDamage += TempTree->TalentList[Index].Talent->BlockDamage;

				StatsContainer.Accuracy += TempTree->TalentList[Index].Talent->Accuracy;
				StatsContainer.Evasion += TempTree->TalentList[Index].Talent->Evasion;

				StatsContainer.CritRate += TempTree->TalentList[Index].Talent->CritRate;
				StatsContainer.CritDamage += TempTree->TalentList[Index].Talent->CritDamage;

				StatsContainer.DamageBleed += TempTree->TalentList[Index].Talent->DamageBleed;
				StatsContainer.DamagePoison += TempTree->TalentList[Index].Talent->DamagePoison;

				StatsContainer.StealHealth += TempTree->TalentList[Index].Talent->StealHealth;
				StatsContainer.StealMana += TempTree->TalentList[Index].Talent->StealMana;
				StatsContainer.StealEnergy += TempTree->TalentList[Index].Talent->StealEnergy;

				StatsContainer.Exp += TempTree->TalentList[Index].Talent->Exp;
				StatsContainer.Gold += TempTree->TalentList[Index].Talent->Gold;
				StatsContainer.DropRate += TempTree->TalentList[Index].Talent->DropRate;

				StatsContainer.AttackSpeed += TempTree->TalentList[Index].Talent->AttackSpeed;
				StatsContainer.AttackSpeedModifier += TempTree->TalentList[Index].Talent->AttackSpeedModifier;
			}
		}

		Stats = StatsContainer;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Not valid"));
	}
}

void AMob_2DChar::ApplyStatChanges(FStruct_StatsHolder& Stats, TArray<FStruct_ItemWrapper> Equipment)
{

		UE_LOG(LogTemp, Warning, TEXT("is valid"));

		FStruct_StatsHolder StatsContainer;
		
		for (int32 Index = 0; Index != Equipment.Num(); ++Index) // for every talent add stats up
		{

			StatsContainer.HealthMax += Equipment[Index].item->HealthMax;
			StatsContainer.HealthRegen += Equipment[Index].item->HealthRegen;

			StatsContainer.ManaMax += Equipment[Index].item->ManaMax;
			StatsContainer.ManaRegen += Equipment[Index].item->ManaRegen;

			StatsContainer.EnergyMax += Equipment[Index].item->EnergyMax;
			StatsContainer.EnergyRegen += Equipment[Index].item->EnergyRegen;

			StatsContainer.DamagePhysical += Equipment[Index].item->DamagePhysical;
			StatsContainer.DamageMagical += Equipment[Index].item->DamageMagical;

			StatsContainer.DefensePhysical += Equipment[Index].item->DefensePhysical;
			StatsContainer.DefenseMagical += Equipment[Index].item->DefenseMagical;

			StatsContainer.BlockChance += Equipment[Index].item->BlockChance;
			StatsContainer.BlockDamage += Equipment[Index].item->BlockDamage;

			StatsContainer.Accuracy += Equipment[Index].item->Accuracy;
			StatsContainer.Evasion += Equipment[Index].item->Evasion;
				
			StatsContainer.CritRate += Equipment[Index].item->CritRate;
			StatsContainer.CritDamage += Equipment[Index].item->CritDamage;

			StatsContainer.DamageBleed += Equipment[Index].item->DamageBleed;
			StatsContainer.DamagePoison += Equipment[Index].item->DamagePoison;

			StatsContainer.StealHealth += Equipment[Index].item->StealHealth;
			StatsContainer.StealMana += Equipment[Index].item->StealMana;
			StatsContainer.StealEnergy += Equipment[Index].item->StealEnergy;

			StatsContainer.Exp += Equipment[Index].item->Exp;
			StatsContainer.Gold += Equipment[Index].item->Gold;
			StatsContainer.DropRate += Equipment[Index].item->DropRate;

			StatsContainer.AttackSpeed += Equipment[Index].item->AttackSpeed;
			StatsContainer.AttackSpeedModifier += Equipment[Index].item->AttackSpeedModifier;

		Stats = StatsContainer; 
	}
}

void AMob_2DChar::ApplyStatsToGPE(TSubclassOf<UGameplayEffect> GPE, FStruct_StatsHolder Stats)
{
	FGameplayEffectContextHandle Temp;

	FGameplayEffectSpecHandle GESH = AbilitySystem->MakeOutgoingSpec(GPE, 1, Temp);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Health"), false), Stats.HealthMax);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Health.Regen"), false), Stats.HealthRegen);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Mana"), false), Stats.ManaMax);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Mana.Regen"), false), Stats.ManaRegen);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Energy"), false), Stats.EnergyMax);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Energy.Regen"), false), Stats.EnergyRegen);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Damage.Phyiscal"), false), Stats.DamagePhysical);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Damage.magical"), false), Stats.DamageMagical);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Defense.Physical"), false), Stats.DefensePhysical);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Defense.Magical"), false), Stats.DefenseMagical);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Block.Rate"), false), Stats.BlockChance);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Block.Rate"), false), Stats.BlockDamage);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Accuracy"), false), Stats.Accuracy);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Evasion"), false), Stats.Evasion);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Crit.Rate"), false), Stats.CritRate);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Crit.Damage"), false), Stats.CritDamage);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Damage.Bleed"), false), Stats.DamageBleed);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Damage.Poison"), false), Stats.DamagePoison);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Health.Steal"), false), Stats.StealHealth);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Mana.Steal"), false), Stats.StealMana);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Energy.Steal"), false), Stats.StealEnergy);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Exp"), false), Stats.Exp);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.Gold"), false), Stats.Gold);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.DropRate"), false), Stats.DropRate);

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.AttackSpeed"), false), Stats.AttackSpeed);
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(GESH, FGameplayTag::RequestGameplayTag(TEXT("Equipment.Base.AttackSpeed.Modifier"), false), Stats.AttackSpeedModifier);


	AbilitySystem->BP_ApplyGameplayEffectSpecToSelf(GESH);

}

//// Movement

void AMob_2DChar::UpdateNavigationRelevance()
{
	if (CollisionComponent)
	{
		CollisionComponent->SetCanEverAffectNavigation(bCanAffectNavigationGeneration);
	}
}

UPawnMovementComponent* AMob_2DChar::GetMovementComponent() const
{
	return MovementComponent;
}

void AMob_2DChar::MoveRight(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
		}
	}
}

void AMob_2DChar::MoveForward(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
		}
	}
}

void AMob_2DChar::MoveUp_World(float Val)
{
	if (Val != 0.f)
	{
		AddMovementInput(FVector::UpVector, Val);
	}
}

void InitializeDefaultPawnInputBindings2()
{
	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Up, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Down, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Gamepad_LeftY, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::Gamepad_LeftX, 1.f));

		// HACK: Android controller bindings in ini files seem to not work
		//  Direct overrides here some to work
#if !PLATFORM_ANDROID
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_LeftThumbstick, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_RightThumbstick, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_FaceButton_Bottom, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::LeftControl, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::SpaceBar, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::C, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::E, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Q, -1.f));
#else
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_LeftTriggerAxis, -0.5f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_RightTriggerAxis, 0.5f));
#endif

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_TurnRate", EKeys::Gamepad_RightX, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_TurnRate", EKeys::Left, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_TurnRate", EKeys::Right, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Turn", EKeys::MouseX, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_LookUpRate", EKeys::Gamepad_RightY, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_LookUp", EKeys::MouseY, -1.f));
	}
}

void AMob_2DChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	if (bAddDefaultMovementBindings)
	{
		InitializeDefaultPawnInputBindings2();

		PlayerInputComponent->BindAxis("DefaultPawn_MoveForward", this, &AMob_2DChar::MoveForward);
		PlayerInputComponent->BindAxis("DefaultPawn_MoveRight", this, &AMob_2DChar::MoveRight);
		PlayerInputComponent->BindAxis("DefaultPawn_MoveUp", this, &AMob_2DChar::MoveUp_World);
		PlayerInputComponent->BindAxis("DefaultPawn_Turn", this, &AMob_2DChar::AddControllerYawInput);
		//PlayerInputComponent->BindAxis("DefaultPawn_TurnRate", this, &AMob_2DChar::TurnAtRate);
		PlayerInputComponent->BindAxis("DefaultPawn_LookUp", this, &AMob_2DChar::AddControllerPitchInput);
		//PlayerInputComponent->BindAxis("DefaultPawn_LookUpRate", this, &AMob_2DChar::LookUpAtRate);
	}
}

