// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::AdjustBarrel(float VerticalDelta, float HorizontalDelta)
{
	float VBarrelSpeed = FMath::Clamp<float>(VerticalDelta, -1, 1);

	float ElevationChange = VBarrelSpeed * MaxElevationDregreesPerSecond * GetWorld()->DeltaTimeSeconds;

	float RawNewElevation = GetAttachParent()->GetRelativeRotation().Pitch + ElevationChange;

	float ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinimumElevation, MaximunElevation);

	
	float HBarrelSpeed = FMath::Clamp<float>(HorizontalDelta, -1, 1);

	float RotationChange = HBarrelSpeed * MaxRotationDregreesPerSecond * GetWorld()->DeltaTimeSeconds;

	float RawNewRotation = GetAttachParent()->GetRelativeRotation().Yaw + RotationChange;

	float ClampedRotation = RawNewRotation;

	GetAttachParent()->SetRelativeRotation(FRotator(ClampedElevation, ClampedRotation, 0));

	//UE_LOG(LogTemp, Warning, TEXT("Elevating at %f"), VerticalDelta);
	//UE_LOG(LogTemp, Error, TEXT("Rotating at %f"), HorizontalDelta);
}