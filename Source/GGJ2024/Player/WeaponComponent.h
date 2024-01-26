// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponComponent.generated.h"

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
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn Point", meta = (AllowPrivateAccess = true))
	TObjectPtr<USceneComponent> SpawnPoint; 
};
