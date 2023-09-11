// Copyright Brandon Hillig


#include "Player/GPlayerController.h"
#include "../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "Interfaces/GEnemyInterface.h"

AGPlayerController::AGPlayerController()
{
}

void AGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ULocalPlayer* LP = GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	ensureMsgf(Subsystem, TEXT("EnhancedInputLPSubsystem is not valid on player: %s"), *GetNameSafe(this));

	Subsystem->ClearAllMappings();

	Subsystem->AddMappingContext(DefaultMappingContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetHideCursorDuringCapture(false);
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);

	SetInputMode(InputModeData);
}

void AGPlayerController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);

	CursorTrace();
}


void AGPlayerController::CursorTrace()
{
	FHitResult OutHit;
	GetHitResultUnderCursor(ECC_Visibility, false, OutHit);

	if (!OutHit.bBlockingHit) return;
	
	LastActor = CurrentActor;
	CurrentActor = Cast<IGEnemyInterface>(OutHit.GetActor());

	if (!LastActor)
	{
		if (CurrentActor)
		{
			CurrentActor->HighlightActor();
		}
	}
	else
	{
		if (CurrentActor)
		{
			if (LastActor != CurrentActor)
			{
				LastActor->UnHighlightActor();
				CurrentActor->HighlightActor();
			}
		}
		else
		{
			LastActor->UnHighlightActor();
		}
	}
	
}

void AGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(InputComponent);

	Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGPlayerController::OnMove);
}

void AGPlayerController::OnMove(const FInputActionValue& InputValue)
{
	const FVector2D AxisValue = InputValue.Get<FVector2D>();

	const FRotator ControlRot = GetControlRotation();
	const FRotator YawRot = FRotator(0.0f, ControlRot.Yaw, 0.0f);

	const FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(YawRot);
	const FVector RightDirection = UKismetMathLibrary::GetRightVector(YawRot);

	if (APawn* MyPawn = GetPawn<APawn>())
	{
		MyPawn->AddMovementInput(ForwardDirection, AxisValue.X);
		MyPawn->AddMovementInput(RightDirection, AxisValue.Y);
	}
	
}
