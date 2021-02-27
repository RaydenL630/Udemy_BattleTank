// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetProjectileSpawnPoint(USceneComponent* ComponentToSet)
{
	ProjectileSpawnPoint = ComponentToSet;
	if (ComponentToSet)
	{
	UE_LOG(LogTemp, Warning, TEXT("Aimingcomponent knows where to spawn projectiles"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Projectile Spawn Unkown"));
	}
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::TakeAim(FVector TargetLocation) const
{
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s"), *GetName(), *TargetLocation.ToString());
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

