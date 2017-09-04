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
	
	//Find Tank to control for AI
	/*
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIConroller has no Control"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController has control: %s"), *(ControlledTank->GetName()));
		
	}
	*/
	//find Player and target
	/*
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI has not found PlayerController"));
	}
	else
	{
	//	UE_LOG(LogTemp, Warning, TEXT("AI tank : %s found Player controlling: %s"), *(ControlledTank->GetName()),*(PlayerTank->GetName()));
		AimAtPlayer();
		//UE_LOG(LogTemp, Warning, TEXT("AI tank : %s is Aiming at Player controlling: %s"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
	}
	*/
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
//refacoting
/*
	AimAtPlayer();
	
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
	*/
	//fire at player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire();
}
/*
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}*/
/*
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	
	return Cast<ATank>(PlayerPawn);

}*/
/*
void ATankAIController::AimAtPlayer()
{
	if (!GetControlledTank())
	{
		return;
	}
	
	//UE_LOG(LogTemp, Warning, TEXT("AI should be aiming"));
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}
*/