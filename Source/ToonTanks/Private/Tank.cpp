// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::Fire()
{
	bool isLoaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isLoaded) 
	{ 
		FActorSpawnParameters SpawnParams;

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetComponentLocation(), Barrel->GetComponentRotation(), SpawnParams);

		Projectile->LaunchProjectile(LaunchSpeed);

		UE_LOG(LogTemp, Warning, TEXT("Firing"));

		LastFireTime = FPlatformTime::Seconds();

	}
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->TakeAim(HitLocation, LaunchSpeed);
}

void ATank::SetProjectileSpawnPointReference(UTankBarrel* ComponentToSet)
{
	TankAimingComponent->SetProjectileSpawnPoint(ComponentToSet);
	Barrel = ComponentToSet;
}

