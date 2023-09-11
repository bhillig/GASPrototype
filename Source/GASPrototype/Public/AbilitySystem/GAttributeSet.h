// Copyright Brandon Hillig

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASPROTOTYPE_API UGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UGAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	/* Attribute Data */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthMax, Category = "Attributes")
	FGameplayAttributeData HealthMax;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Attributes")
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaMax, Category = "Attributes")
	FGameplayAttributeData ManaMax;

	/* Attribute Accessors */

	ATTRIBUTE_ACCESSORS(UGAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UGAttributeSet, HealthMax);
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UGAttributeSet, ManaMax);

	/* OnRep Attributes */

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_ManaMax(const FGameplayAttributeData& OldManaMax) const;

};
