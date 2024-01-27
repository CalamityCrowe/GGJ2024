// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefendPoint.generated.h"

class UBoxComponent;

UCLASS()
class GGJ2024_API ADefendPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADefendPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const { return (Health / MaxHealth); }

	UFUNCTION(BlueprintPure)
	bool GetIsDestroyed() const { return IsDestroyed; }

	void DamageDefendPoint(float Damage)
	{
		Health -= Damage; if (Health <= 0) { IsDestroyed = true; }
	}

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UBoxComponent> Collider;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
	float Health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
	float MaxHealth;

	bool IsDestroyed;
};
