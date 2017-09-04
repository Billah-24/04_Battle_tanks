// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Components/ActorComponent.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	//fire at player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire();
}
