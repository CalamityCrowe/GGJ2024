// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Base_EnemyController.generated.h"

class ADefendPoint;
/**
 *
 */
UCLASS()
class GGJ2024_API ABase_EnemyController : public AAIController
{
	GENERATED_BODY()
public:
	ABase_EnemyController();
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public:

	void MoveEnemy();

	TObjectPtr<AActor> GetTarget()const { return TargetPoint; }

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Target Actor", meta = (AllowPrivateAccess = true))
	TObjectPtr<AActor> TargetPoint;

};
