// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "BattleTank.h"
#include "TankBarrel.generated.h"

/**
 * //,hidecategories =("Collision));
 */
//hold barrel data 
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	// -1 is max downward speed +1 max up speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 37;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = -1;
};
