// Fill out your copyright notice in the Description page of Project Settings.




#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();	
	

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController has no Control"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController has control: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	

	return Cast<ATank>(GetPawn());

}
