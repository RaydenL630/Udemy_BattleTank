// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TankPlayerController.h"
#include "DrawDebugHelpers.h"

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
		GetControlledTank()->AimAt(HitLocation);
	} 


}

bool ACPP_TankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	
	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);
	
	FVector2D ScreenLocation(CrossHairLocationX * VieportSizeX, CrossHairLocationY * VieportSizeY);

	FVector DeprojectDirection;
	FVector CameraWorldLocation; //Need to store it, then being discard.

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, DeprojectDirection))
	{
		GetLookVectorHitLocation(DeprojectDirection, OutHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("%s - Hit Direction"), *DeprojectDirection.ToString());
		return true;
	}

	return false;
}

bool ACPP_TankPlayerController::GetLookVectorHitLocation(FVector TraceDirection, FVector& HitLocation) const
{
	FVector TraceStart = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
	FCollisionQueryParams TraceParams(TEXT(""), false, this);
	FHitResult OutHit;

	bool AimingTrace = GetWorld()->LineTraceSingleByChannel(OutHit, TraceStart, TraceStart + TraceDirection * LineTraceRange, ECollisionChannel::ECC_Visibility, TraceParams);
	
	//DrawDebugLine(GetWorld(), TraceStart, TraceStart + TraceDirection * LineTraceRange, FColor(uint8 255, uint8 0, uint8 0), false, float -1.f, uint8 0, float 10.f);

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
