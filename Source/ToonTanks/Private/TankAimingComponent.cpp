// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetProjectileSpawnPoint(UTankBarrel* ComponentToSet)
{
	ProjectileSpawnPoint = ComponentToSet;
	if (ComponentToSet)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Aimingcomponent knows where to spawn projectiles"));
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("Projectile Spawn Unkown"));
	}
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::TakeAim(FVector TargetLocation, float LaunchSpeed) const
{
	if (!ProjectileSpawnPoint) { return; }

	FVector ProjectileVelocity;
	FCollisionResponseParams CollisionResponseParams;

	TArray<AActor*> ActorsToIgnore;

	bool Prediction= UGameplayStatics::SuggestProjectileVelocity(this, ProjectileVelocity, ProjectileSpawnPoint->GetComponentLocation(), TargetLocation, LaunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace, CollisionResponseParams, ActorsToIgnore, false);

	if (Prediction)
	{
		MoveBarrel(ProjectileVelocity);
	}

}


void UTankAimingComponent::MoveBarrel(FVector TargetVector) const
{
	FRotator CurrentRotation = ProjectileSpawnPoint->GetAttachParent()->GetComponentRotation();
	FRotator AimAsRotation = TargetVector.Rotation();
	FRotator DeltaRotation = AimAsRotation - CurrentRotation;

	ProjectileSpawnPoint->AdjustBarrel(DeltaRotation.Pitch, DeltaRotation.Yaw);

	//ProjectileSpawnPoint->GetAttachParent()->SetWorldRotation(AimAsRotation);
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

