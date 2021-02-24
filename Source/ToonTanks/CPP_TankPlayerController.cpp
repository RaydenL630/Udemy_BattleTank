// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TankPlayerController.h"

void ACPP_TankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Target = GetControlledTank();
	
	if (Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank actor found: %s"), *Target->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank actor found"));
	}
	
}

ATank* ACPP_TankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};