// Copyright Brandon Hillig


#include "GBaseCharacter.h"

AGBaseCharacter::AGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

