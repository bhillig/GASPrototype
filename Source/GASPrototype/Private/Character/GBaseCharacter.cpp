// Copyright Brandon Hillig


#include "Character/GBaseCharacter.h"

AGBaseCharacter::AGBaseCharacter()
	: WeaponSocketName("WeaponHandSocket")
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), WeaponSocketName);
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* AGBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
