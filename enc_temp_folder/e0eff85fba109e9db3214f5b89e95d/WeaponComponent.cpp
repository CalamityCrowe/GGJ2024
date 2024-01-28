// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"

#include <Windows.ApplicationModel.DataTransfer.ShareTarget.h>

#include "Base_Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GGJ2024/Base_Projectile.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AWeaponComponent::AWeaponComponent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	RootComponent = Mesh;

	SpawnPoint = CreateOptionalDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(Mesh);
	BowCharge = 0; 
}

// Called when the game starts or when spawned
void AWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeapon = EWeaponType::Bow; 
}



void AWeaponComponent::AimProjectile()
{

	FVector StartPos = GetActorLocation();
	// Convert the vector components to a string
	FString StartPosString = FString::Printf(TEXT("StartPos: X=%.2f, Y=%.2f, Z=%.2f"), StartPos.X, StartPos.Y, StartPos.Z);

	// Display the string on the screen using AddOnScreenDebugMessage
	FString Key = TEXT("StartPosDebugMessage");


	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, StartPosString, false);	FVector LaunchVelocity;



	FPredictProjectilePathResult PredictResult;
	//handles the logic for the projectile velocity
	switch (CurrentWeapon)
	{
	case EWeaponType::Bow:

		BowCharge += GetWorld()->GetDeltaSeconds() * 200;
		if (BowCharge > 3000)
		{
			BowCharge = 3000;
		}

		LaunchVelocity = SpawnPoint->GetForwardVector() * BowCharge;

		break;

	case EWeaponType::Bomb:
		LaunchVelocity = SpawnPoint->GetForwardVector() * 1500;
		break;

	}

	
	FPredictProjectilePathParams PredictParams(0.0f, StartPos, LaunchVelocity, 2.0f, ECollisionChannel::ECC_Visibility);

	if (UGameplayStatics::PredictProjectilePath(this, PredictParams, PredictResult))
	{

		for (auto predictPoint : PredictResult.PathData)
		{
			const FVector predictVector = predictPoint.Location;
			const FRotator newRot;
			FActorSpawnParameters SpawnParams;

			if (GetWorld()->SpawnActor<AActor>(TrajctoryRef, predictVector, newRot, SpawnParams))
			{
				GEngine->AddOnScreenDebugMessage(0, 10, FColor::Red, "SpawningPath");
			}
		}
	}
}

void AWeaponComponent::SpawnProjectile()
{
	// do the fire logic

	FVector SpawnPos = GetActorLocation();
	FRotator SpawnRot = GetActorRotation();

	FActorSpawnParameters SpawnParamets;



	switch (CurrentWeapon)
	{
	case EWeaponType::Bow:
		if (ABase_Projectile* TempProjectile = GetWorld()->SpawnActor<ABase_Projectile>(ArrowRef, SpawnPos, SpawnRot, SpawnParamets))
		{
			FVector LaunchVelocity = SpawnPoint->GetForwardVector() * BowCharge;

			TempProjectile->GetProjectileMovementComponent()->Velocity = LaunchVelocity; 
		}
		break;

	case EWeaponType::Bomb:

		if (ABase_Projectile* TempProjectile = GetWorld()->SpawnActor<ABase_Projectile>(GrenadeRef, SpawnPos, SpawnRot, SpawnParamets))
		{
			FVector LaunchVelocity = SpawnPoint->GetForwardVector() * 1500;

			TempProjectile->GetProjectileMovementComponent()->Velocity = LaunchVelocity;
		}
		break;
	}
	BowCharge = 0;
}

void AWeaponComponent::BindWeaponInputs(ABase_Character* PlayerRef)
{

	if (PlayerRef == nullptr)
	{
		return;
	}

	if (APlayerController* PC = Cast<APlayerController>(PlayerRef->GetController()))
	{

		if (UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PC->InputComponent))
		{
			//PEI->BindAction(WeaponInputData->IaFireWeapon,ETriggerEvent::Triggered,this)
			PEI->BindAction(PlayerRef->IA_Shoot, ETriggerEvent::Triggered, this, &AWeaponComponent::AimProjectile);
 			PEI->BindAction(PlayerRef->IA_Shoot, ETriggerEvent::Completed, this, &AWeaponComponent::SpawnProjectile);
	

			GEngine->AddOnScreenDebugMessage(1, 2, FColor::Purple, TEXT("WeaponBOund"));
		}
	}
}

