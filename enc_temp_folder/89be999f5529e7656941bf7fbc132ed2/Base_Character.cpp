// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Character.h"
#include  "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ABase_Character::ABase_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
}

// Called when the game starts or when spawned
void ABase_Character::BeginPlay()
{
	Super::BeginPlay();
	
	if (const APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(PlayerContexMapping, 1);
		}
	}
}

// Called every frame
void ABase_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABase_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = CastChecked< UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInput->BindAction(PlayerMovement, ETriggerEvent::Triggered, this, &ABase_Character::Move);
		

	}
}

void ABase_Character::Move(const FInputActionValue& Value)
{
	
		const FVector2D MoveValue = Value.Get<FVector2D>();

		const FRotator ControllerForwardRotation = GetControlRotation();
		const FRotator ControllerForwardYaw(0, ControllerForwardRotation.Yaw, 0);

		const FVector DirectionForward = FRotationMatrix(ControllerForwardYaw).GetUnitAxis(EAxis::X);


		const FRotator ControllerRightRotation = GetControlRotation();
		const FRotator ControllerRightYaw(0, ControllerRightRotation.Yaw, 0);

		const FVector DirectionRight = FRotationMatrix(ControllerRightYaw).GetUnitAxis(EAxis::Y);

		AddMovementInput(DirectionForward, MoveValue.Y);
		AddMovementInput(DirectionRight, MoveValue.X);

}