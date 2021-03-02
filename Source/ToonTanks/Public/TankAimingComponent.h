// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;//Forward Declaration

//Component that processes the aiming of "Tank" type pawns.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetProjectileSpawnPoint(UTankBarrel* ComponentToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UTankBarrel* ProjectileSpawnPoint = nullptr;

	void MoveBarrel(FVector TargetVector) const;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeAim(FVector TargetLocation, float LaunchSpeed) const;
		
};
