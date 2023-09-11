// Copyright Brandon Hillig


#include "AbilitySystem/GAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UGAttributeSet::UGAttributeSet()
{
	InitHealth(100.0f);
	InitHealthMax(100.0f);
	InitMana(80.0f);
	InitManaMax(80.0f);
}

void UGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Health, OldHealth);
}

void UGAttributeSet::OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, HealthMax, OldHealthMax);
}

void UGAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Mana, OldMana);
}

void UGAttributeSet::OnRep_ManaMax(const FGameplayAttributeData& OldManaMax) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, ManaMax, OldManaMax);
}

void UGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, HealthMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, ManaMax, COND_None, REPNOTIFY_Always);
}