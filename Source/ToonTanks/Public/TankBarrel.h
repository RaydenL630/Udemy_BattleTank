// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOONTANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere)
	float MaxElevationDregreesPerSecond = 5;

	UPROPERTY(EditAnywhere)
	float MaxRotationDregreesPerSecond = 50;

	UPROPERTY(EditAnywhere)
	float MaximunElevation = 20;

	UPROPERTY(EditAnywhere)
	float MinimumElevation = -15;

public:
	//Clamped to : -1 is max downward speed and +1 is max upwards speed.
	void AdjustBarrel(float VerticalDelta, float HorizontalDelta);
};
