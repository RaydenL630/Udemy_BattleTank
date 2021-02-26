// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ACPP_TankPlayerController : public APlayerController
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
	float LineTraceRange = 300.f;
	
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector TraceDirection, FVector& HitLocation) const;
	
	ATank* GetControlledTank() const;
	
	/*FVector2D FindScreenLocation();*/


};
