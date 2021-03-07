// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	//if (ControlledActor)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AI controlling: %s"), *ControlledActor->GetName());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Error, TEXT("AI controller failed to possess!"));
	//}


	/*if (PlayerTank)
	{
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank not found!"));

	}*/
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* ControlledActor = Cast<ATank>(GetPawn());

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
	FVector PlayerLocation = PlayerTank->GetActorLocation();

	ControlledActor->AimAt(PlayerLocation);
	}


}