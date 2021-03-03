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
		float MaxDregreesPerSecond = 20;

	UPROPERTY(EditAnywhere)
		float MaximunElevation = 20;

	UPROPERTY(EditAnywhere)
		float MinimumElevation = 20;

public:
	//Clamped to : -1 is max downward speed and +1 is max upwards speed.
	void ElevateBarrel(float RelativeSpeed);
};
