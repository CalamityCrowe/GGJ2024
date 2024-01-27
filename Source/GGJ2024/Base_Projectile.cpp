// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Projectile.h"

#include "Components/SphereComponent.h"
#include "Enemy/Base_Enemy.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABase_Projectile::ABase_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateOptionalDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = Collider;

	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	ProjectileMovement = CreateOptionalDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABase_Projectile::OnOverlap); 

}

// Called when the game starts or when spawned
void ABase_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABase_Projectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(ABase_Enemy* TempEnemy = Cast<ABase_Enemy>(OtherActor))
	{
		TempEnemy->DamageEnemy(ProjectileDamage);
		if(TempEnemy->GetIsDead())
		{
			TempEnemy->DestroyEnemy(); // destroys the enemy if they are dead along with their controller 
		}
	}
	ProjectileHitLogic(); 
}

