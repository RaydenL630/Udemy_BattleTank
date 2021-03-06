// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Reticle Screen Location")
		float CrossHairLocationX = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Reticle Screen Location")
		float CrossHairLocationY = 0.33333f;

	UPROPERTY(EditAnywhere, Category = "Reticle Screen Location")
		float LineTraceRange = 100000.f;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector TraceDirection, FVector& HitLocation) const;

	ATank* GetControlledTank() const;

	/*FVector2D FindScreenLocation();*/


};
