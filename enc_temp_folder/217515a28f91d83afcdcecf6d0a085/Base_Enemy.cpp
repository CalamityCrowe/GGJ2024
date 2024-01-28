// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Enemy.h"

#include "Base_EnemyController.h"

// Sets default values
ABase_Enemy::ABase_Enemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABase_Enemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABase_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (EnemyController && IsInRange() == false)
	{
		EnemyController->MoveEnemy();
	}
	else
	{
		// do enemy attack logic here
	}
}

// Called to bind functionality to input
void ABase_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void ABase_Enemy::AssignAIController()
{
	if (GetController())
	{
		if (EnemyController = Cast<ABase_EnemyController>(GetController()))
		{
			GEngine->AddOnScreenDebugMessage(2, 3, FColor::Purple, TEXT("Controller Assigned"));
		}
	}
}

void ABase_Enemy::DestroyEnemy()
{
	EnemyController->Destroy();
	Destroy(); 
}

bool ABase_Enemy::IsInRange() const
{
	return	(GetActorLocation().SquaredLength() - EnemyController->GetTarget()->GetActorLocation().SquaredLength()) < 200;
}

