// Copyright Brandon Hillig

#pragma once

#include "CoreMinimal.h"
#include "Character/GBaseCharacter.h"
#include "GPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class GASPROTOTYPE_API AGPlayerCharacter : public AGBaseCharacter
{
	GENERATED_BODY()

public:
	AGPlayerCharacter();

	virtual void OnRep_PlayerState() override;

	virtual void PossessedBy(AController* NewController) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;

private:

	void SetupAbilitySystem();

};
