// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
//#include "Runtime/Engine/Classes/Components/SceneComponent.h"
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
void UTankAimingComponent::AimAt(FVector HitLocation)
{
	auto OurTankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: AimAt test.. barrelLocation next... "),*OurTankName);
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s "), *OurTankName, *HitLocation.ToString());
	//check(Barrel);
//	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s "), *OurTankName, *HitLocation.ToString(), *BarrelLocation);

}
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) 
{
	Barrel = BarrelToSet;
	FString BarrelName = BarrelToSet->GetFName().ToString();
	FString BarrelLocation = BarrelToSet->GetSocketLocation("TubeAsmbly").ToString();
	GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, FString::Printf(TEXT("Barrel Name: %s  Barrel Location: %s"), *BarrelName, *BarrelLocation));

	}
