// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
//#include "Components/ActorComponent.h"
#include  "Classes/Engine/Engine.h"
#include "Classes/Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
/*	
	FString BarrelLocation = "";
	if (Barrel)
	{
		BarrelLocation = Barrel->GetComponentLocation().ToString();
		UE_LOG(LogTemp, Warning, TEXT("%s: AimAt test.. if barrelLocation complete... "),*OurTankName);
	}
	//check(Barrel);
*/
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s "), *OurTankName, *HitLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s "), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
	//GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, FString::Printf(TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(),*BarrelLocation));
	UE_LOG(LogTemp, Warning, TEXT("%s is Firing at %f "), *OurTankName, LaunchSpeed);
}
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) 
{
	Barrel = BarrelToSet;
	if (Barrel)
	{
		FString BarrelName = BarrelToSet->GetFName().ToString();
		FString BarrelLocation = BarrelToSet->GetSocketLocation("Barrel").ToString();
		//GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, FString::Printf(TEXT("Barrel Name: %s  Barrel Location: %s"), *BarrelName, *BarrelLocation));
	}
}
