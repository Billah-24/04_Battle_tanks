// Fill out your copyright notice in the Description page of Project Settings.



#include "TankAIController.h"
//#include "BattleTank.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();
	

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIConroller has no Control"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController has control: %s"), *(ControlledTank->GetName()));
		
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI has not found PlayerController or has no Control"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found Player controlling: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	
	return Cast<ATank>(PlayerPawn);

}