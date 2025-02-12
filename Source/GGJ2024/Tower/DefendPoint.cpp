// Fill out your copyright notice in the Description page of Project Settings.


#include "DefendPoint.h"

#include "Components/BoxComponent.h"

// Sets default values
ADefendPoint::ADefendPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateOptionalDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;

	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	Health = 100;
	MaxHealth = Health; 
}

// Called when the game starts or when spawned
void ADefendPoint::BeginPlay()
{
	Super::BeginPlay();

	MaxHealth = Health; 
}

// Called every frame
void ADefendPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

