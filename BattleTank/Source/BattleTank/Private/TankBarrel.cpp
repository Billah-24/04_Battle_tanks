// Fill out your copyright notice in the Description page of Project Settings.



#include "TankBarrel.h"
#include "BattleTank.h"

#include "Components/ActorComponent.h"
#include "Tank.h"


void UTankBarrel::Elevate(float RelativeSpeed) 
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;


	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation , MaxElevation );

	SetRelativeRotation(FRotator(Elevation, 0, 0));

}


