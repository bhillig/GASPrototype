// Copyright Brandon Hillig

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GEnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GASPROTOTYPE_API IGEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void HighlightActor() = 0;

	virtual void UnHighlightActor() = 0;
};
