// Fill out your copyright notice in the Description page of Project Settings.




#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Tank.h"

#define OUT
//


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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // Call parent class tick function  

//	UE_LOG(LogTemp, Warning, TEXT("Tick!. Player controller says!"));
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimAtCrosshair() 
{
	if (!GetControlledTank())
	{	return;	}

	FVector HitLocation; //Out param
	if (GetSightRayHitLocation(HitLocation))
	{
	//	UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		GetControlledTank()->AimAt(HitLocation);

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const
{
	//Screen coords from crosshair.
	int32 ViewportSize_X, ViewportSize_Y;
	GetViewportSize(ViewportSize_X, ViewportSize_Y);
	auto ScreenLocation = FVector2D(ViewportSize_X * CrossHairXLocation, ViewportSize_Y * CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direciton: %s"), *LookDirection.ToString());
		if (GetLookVectorHitLocation(LookDirection, outHitLocation))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Hit Something"));
		}
	}

	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{

	//deproject sceen pos from player controller
	FVector CameraWorldLocation;
	
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	//UE_LOG(LogTemp, Warning, TEXT("Look direciton: %s"), *LookDirection.ToString());
	//return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& outHitLocation) const
{
	FHitResult LineTraceHitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
		if(GetWorld()->LineTraceSingleByChannel(
			LineTraceHitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility))
		{
			outHitLocation = LineTraceHitResult.Location;
			return true;
		}
		outHitLocation = FVector (0.0);
		return false;
 
}
