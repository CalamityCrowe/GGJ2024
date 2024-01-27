// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"

// Sets default values
UWeaponComponent::UWeaponComponent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	

	SpawnPoint = CreateOptionalDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeaponComponent::AimProjectile()
{
	// do the aim logic here
}

void UWeaponComponent::SpawnProjectile()
{
	// do the fire logic
	switch (CurrentWeapon)
	{
	case EWeaponType::Bow:


		break;

	case EWeaponType::Bomb:


		break;
	}
}

