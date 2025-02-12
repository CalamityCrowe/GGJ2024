// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnPoint.generated.h"

class ABase_Enemy;

UCLASS()
class GGJ2024_API AEnemySpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemySpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SpawnEnemy();


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Reference", meta = (AllowPrivateAccess = true))
	TSubclassOf<ABase_Enemy> EnemyRef;

};
