// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TankPlayerController.h"

void ACPP_TankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//this->execSetActorTickEnabled(this, FFrame, true);

	ATank* Target = GetControlledTank();
	
	if (Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank actor found: %s"), *Target->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank actor found"));
	}
	
}

void ACPP_TankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ACPP_TankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Error, TEXT("Hit Location: %s"), *HitLocation.ToString());
	} 


}

bool ACPP_TankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	
	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);
	
	FVector2D ScreenLocation(CrossHairLocationX * VieportSizeX, CrossHairLocationY * VieportSizeY);

	FVector DeprojectDirection;
	FVector CameraWorldLocation;

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, DeprojectDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s - Hit Direction"), *DeprojectDirection.ToString());

		return true;
	}

	return false;
}

/*FVector2D ACPP_TankPlayerController::FindScreenLocation()
{

	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);

	float XLocation = CrossHairLocationX * VieportSizeX;
	float YLocation = CrossHairLocationY * VieportSizeY;


	return ScreenLocation;
}*/

ATank* ACPP_TankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};
