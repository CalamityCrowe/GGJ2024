// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_EnemyController.h"

#include "Base_Enemy.h"
#include "NavigationSystem.h"
#include "GGJ2024/Tower/DefendPoint.h"
#include "Kismet/GameplayStatics.h"


ABase_EnemyController::ABase_EnemyController()
{
}

void ABase_EnemyController::BeginPlay()
{
	Super::BeginPlay();

	
}

void ABase_EnemyController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(TargetPoint == nullptr)
	{
		if (TargetPoint = UGameplayStatics::GetActorOfClass(GetWorld(), ADefendPoint::StaticClass()))
		{
			GEngine->AddOnScreenDebugMessage(22, 2, FColor::Emerald, TEXT("Target Point Assigned")); 
		}
		else{}
	}
}

void ABase_EnemyController::MoveEnemy()
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

	if (APawn* ControlledPawn = GetPawn())
	{
		const ANavigationData* NavData = NavSys->GetDefaultNavDataInstance(FNavigationSystem::DontCreate);

		if (ABase_Enemy* CurrentEnemy = Cast<ABase_Enemy>(ControlledPawn))
		{

			MoveToActor(TargetPoint, 0);


		}

	}
}


