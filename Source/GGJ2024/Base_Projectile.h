// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base_Projectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class GGJ2024_API ABase_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABase_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void ProjectileHitLogic(); 

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Collider", meta = (AllowPrivateAccess = true))
	TObjectPtr<USphereComponent> Collider;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Projectile Movement", meta = (AllowPrivateAccess = true))
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Damage", meta = (AllowPrivateAccess = true))
	int ProjectileDamage; 

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
