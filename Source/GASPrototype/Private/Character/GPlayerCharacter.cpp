// Copyright Brandon Hillig


#include "Character/GPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/GPlayerState.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

AGPlayerCharacter::AGPlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
}

void AGPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	/* Client: Set up ability system */
	SetupAbilitySystem();
}

void AGPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	/* Server: Setup ability system */
	SetupAbilitySystem();
}

void AGPlayerCharacter::SetupAbilitySystem()
{
	/* Retrieve the player state */
	AGPlayerState* PS = CastChecked<AGPlayerState>(GetPlayerState());

	/* Sync the ability system and attribute set */
	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();

	/* Define the ability actor info */
	AbilitySystemComponent->InitAbilityActorInfo(PS, this);
}
