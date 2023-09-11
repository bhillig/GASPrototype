// Copyright Brandon Hillig


#include "Player/GPlayerState.h"
#include "AbilitySystem/GAbilitySystemComponent.h"
#include "AbilitySystem/GAttributeSet.h"

AGPlayerState::AGPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UGAttributeSet>("AttributeSet");

	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
