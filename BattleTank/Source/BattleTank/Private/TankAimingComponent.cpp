// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include  "Classes/Engine/Engine.h"
#include "TankBarrel.h"
#include "Tank.h"
#include "Classes/Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO shoudl this tick

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
		TArray<AActor*> ActorIgnoreList;
		ActorIgnoreList.Add(GetOwner());
	FString BarrelLocation = "";
	if (!Barrel) { return; }

	if (Barrel)
	{
		FVector OutLaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

		//BarrelLocation = Barrel->GetComponentLocation().ToString();
		//Calco outvelocity
		bool bHaveFiringSolution = UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0.0f,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		//	FCollisionResponseParams::DefaultResponseParam,
		//	ActorIgnoreList,
		//	true
		);
		if(bHaveFiringSolution)
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			MoveBarrel(AimDirection);
			//UE_LOG(LogTemp, Warning, TEXT("%s: AimAt test..movebarrel At %s complete... "),*OurTankName, *AimDirection.ToString());
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f: Move Barrel AimDirection found"), Time);
		}
		else
		{
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f: No aim found"), Time);
		}
	}

	//check(Barrel);
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s "), *OurTankName, *HitLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s "), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
	//GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, FString::Printf(TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(),*BarrelLocation));
	//UE_LOG(LogTemp, Warning, TEXT("%s is Firing at %f "), *OurTankName, LaunchSpeed);
}
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	Barrel = BarrelToSet;
	if (!Barrel) { return; }
	if (Barrel)
	{
		FString BarrelName = BarrelToSet->GetFName().ToString();
		FString BarrelLocation = BarrelToSet->GetSocketLocation("Barrel").ToString();
		//GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, FString::Printf(TEXT("Barrel Name: %s  Barrel Location: %s"), *BarrelName, *BarrelLocation));
	}
}
void UTankAimingComponent::MoveBarrel(FVector TargetLocation)
{
	//calc difreence between current direction and then new 
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = TargetLocation.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;

//	UE_LOG(LogTemp, Warning, TEXT("BarrelRotator: %s   AimRotator: %s   Delta: %s"), *BarrelRotator.ToString(), *AimRotator.ToString(), *DeltaRotator.ToString());
	Barrel->Elevate(DeltaRotator.Pitch);
}
