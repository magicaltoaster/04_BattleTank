// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ContolledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// TODO Move towards the player
		//UE_LOG(LogTemp, Warning, TEXT("ticking?"));
		// Aim towards the player
		ContolledTank->AimAt(PlayerTank->GetActorLocation());
		ContolledTank->Fire();
		float ReloadTimeInSeconds = 3;
	}
}

