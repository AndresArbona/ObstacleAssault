// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlataform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlataform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlataform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere,Category="Moving")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere,Category="Rotation")
	FRotator RotationVelocity;
	
	FVector StartLocation;

	//Not-return functions
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	//return functions
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};