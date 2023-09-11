// Copyright Brandon Hillig

#pragma once

#include "CoreMinimal.h"
#include "Character/GBaseCharacter.h"
#include "Interfaces/GEnemyInterface.h"
#include "GEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GASPROTOTYPE_API AGEnemyCharacter : public AGBaseCharacter, public IGEnemyInterface
{
	GENERATED_BODY()
	
public:
	AGEnemyCharacter();

protected:

	virtual void BeginPlay() override;

public:

	/* Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* END Enemy Interface */
};
