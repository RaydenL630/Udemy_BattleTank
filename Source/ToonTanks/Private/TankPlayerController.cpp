// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "DrawDebugHelpers.h"

void ATankPlayerController::BeginPlay()
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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);

	FVector2D ScreenLocation(CrossHairLocationX * VieportSizeX, CrossHairLocationY * VieportSizeY);

	FVector DeprojectDirection;
	FVector CameraWorldLocation; //Need to store it, then being discard.

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, DeprojectDirection))
	{
		GetLookVectorHitLocation(DeprojectDirection, OutHitLocation);
		return true;
	}

	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector TraceDirection, FVector& HitLocation) const
{
	FVector TraceStart = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
	FCollisionQueryParams TraceParams(TEXT(""), false, this);
	FHitResult OutHit;

	bool AimingTrace = GetWorld()->LineTraceSingleByChannel(OutHit, TraceStart, TraceStart + TraceDirection * LineTraceRange, ECollisionChannel::ECC_Visibility, TraceParams);

	if (AimingTrace)
	{
		HitLocation = OutHit.ImpactPoint;
		return true;
	}
	else
	{
		HitLocation = FVector(0);
		return false;
	}
}

/*FVector2D ATankPlayerController::FindScreenLocation()
{

	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);

	float XLocation = CrossHairLocationX * VieportSizeX;
	float YLocation = CrossHairLocationY * VieportSizeY;


	return ScreenLocation;
}*/

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};

