// Copyright Brandon Hillig

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GBaseCharacter.generated.h"

UCLASS()
class GASPROTOTYPE_API AGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGBaseCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
