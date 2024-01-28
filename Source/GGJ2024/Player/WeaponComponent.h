// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponComponent.generated.h"

class ABase_Character;
class ABase_Projectile;

UENUM(BlueprintType)
enum EWeaponType : uint8
{
	Bow  UMETA(DisplayName = "Player Bow"),
	Bomb UMETA(DisplayName = "Kitty Bomb"),

};

UCLASS()
class GGJ2024_API AWeaponComponent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame

	void AimProjectile(); 

	void SpawnProjectile(); 

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn Point", meta = (AllowPrivateAccess = true))
	TObjectPtr<USceneComponent> SpawnPoint;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ammo Reference", meta = (AllowPrivateAccess = true))
	TSubclassOf<ABase_Projectile> ArrowRef;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ammo Reference", meta = (AllowPrivateAccess = true))
	TSubclassOf<ABase_Projectile> GrenadeRef;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trajectory Reference", meta = (AllowPrivateAccess = true))
	TSubclassOf<AActor> TrajctoryRef;

	TEnumAsByte<EWeaponType> CurrentWeapon; 

	float BowCharge;

public:
	UFUNCTION()
	void BindWeaponInputs(ABase_Character* PlayerRef);

};
