// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledActor = GetControlledActor();

	if (ControlledActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controlling: %s"), *ControlledActor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI controller failed to possess!"));
	}

	ATank* PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank found: %s"), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank not found!"));

	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
	FVector PlayerLocation = GetPlayerTank()->GetActorLocation();

	GetControlledActor()->AimAt(PlayerLocation);
	}


}

ATank* ATankAIController::GetControlledActor() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}