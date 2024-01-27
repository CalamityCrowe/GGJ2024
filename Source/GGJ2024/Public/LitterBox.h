// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LitterBox.generated.h"

class ABase_Enemy;
class UBoxComponent;

UCLASS()
class GGJ2024_API ALitterBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALitterBox();
   UFUNCTION(BlueprintCallable, Category = "Health")
  FORCEINLINE float getPlayerHealth(){ return LitterBoxHealth;}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ABase_Enemy* Enemy;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LitterMesh;
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
	float DeductHealth(float health);
	float LitterBoxHealth = 100.f;
public:	
	// Called every frame
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void Tick(float DeltaTime) override;

};
