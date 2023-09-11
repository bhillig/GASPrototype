// Copyright Brandon Hillig

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IGEnemyInterface;

/**
 * 
 */
UCLASS()
class GASPROTOTYPE_API AGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AGPlayerController();
	
protected:

	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

private:

	UFUNCTION()
	void OnMove(const FInputActionValue& InputValue);

	UFUNCTION()
	void CursorTrace();

	IGEnemyInterface* LastActor;
	IGEnemyInterface* CurrentActor;
};
