// Fill out your copyright notice in the Description page of Project Settings.


#include "LitterBox.h"

#include "Components/BoxComponent.h"
#include "GGJ2024/Enemy/Base_Enemy.h"

// Sets default values
ALitterBox::ALitterBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    LitterMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("LitterMesh"));
	RootComponent = LitterMesh;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollider"));
	BoxComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ALitterBox::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&ALitterBox::OnOverlapBegin);
	getPlayerHealth();
}

float ALitterBox::DeductHealth(float health)
{
   return health -=Enemy->DamageValue;
}

void ALitterBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABase_Enemy* Rat = Cast<ABase_Enemy>(OtherActor);
	if (Rat && LitterBoxHealth > 0)
	{
		LitterBoxHealth = DeductHealth(LitterBoxHealth);
		GEngine->AddOnScreenDebugMessage(1, 200, FColor::Red, FString::Printf(TEXT("LitterBox Health Deducted %f"), LitterBoxHealth));
	}
}


// Called every frame
void ALitterBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

