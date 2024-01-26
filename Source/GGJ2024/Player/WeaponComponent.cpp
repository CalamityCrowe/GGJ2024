// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"

// Sets default values
AWeaponComponent::AWeaponComponent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	SpawnPoint = CreateOptionalDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(Mesh); 

}

// Called when the game starts or when spawned
void AWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWeaponComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

