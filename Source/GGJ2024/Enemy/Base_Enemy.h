// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Base_Enemy.generated.h"

class USphereComponent;
class ABase_EnemyController;

UCLASS()
class GGJ2024_API ABase_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABase_Enemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AssignAIController();

	void DamageEnemy(int Damage)
	{
		EnemyHealth -= Damage;
		if (EnemyHealth <= 0) { isDead = true;  }
	}


	bool GetIsDead() const { return isDead;  }

	void DestroyEnemy();
private:
	TObjectPtr<ABase_EnemyController> EnemyController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<USkeletalMeshComponent> SKMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCapsuleComponent> Collider;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Collider", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCapsuleComponent> AttackCollision; 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
	int EnemyHealth;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = true))
	float EnemyDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
	bool isDead; 

	bool IsInRange() const;

private:

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
