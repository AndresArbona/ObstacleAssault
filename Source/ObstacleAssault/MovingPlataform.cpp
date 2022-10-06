// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlataform.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMovingPlataform::AMovingPlataform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlataform::BeginPlay()
{
	Super::BeginPlay();
	//get the initial location
	StartLocation = GetActorLocation();
	
}
// Called every frame
void AMovingPlataform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlataform::MovePlatform(float DeltaTime)
{
	// reverse direction of motion if gone too far
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();//Get the Normal
		StartLocation = StartLocation + MoveDirection * MoveDistance;//Get the finish location and put in the Star location
		SetActorLocation(StartLocation);//Set the new star location
		PlatformVelocity = -PlatformVelocity;//get back the platform
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();	// Get current location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);// Add vector to that location
	SetActorLocation(CurrentLocation);// Set the location
	}
}


void AMovingPlataform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlataform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;// Check how far we've moved
}

float AMovingPlataform::GetDistanceMoved() const
{
	return FVector ::Dist(StartLocation, GetActorLocation());
}

