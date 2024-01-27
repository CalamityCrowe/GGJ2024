// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Base_Character.generated.h"



class UInputAction;
class UInputMappingContext;

UCLASS()
class GGJ2024_API ABase_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABase_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Input);
	UInputAction* PlayerMovement;

	UPROPERTY(EditAnywhere, Category = Input);
	UInputMappingContext* PlayerContexMapping;

	void Move(const FInputActionValue& Value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
