// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	auto playerTank = ATankAIController::GetPlayerTank();
	if (playerTank == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing a tank"));
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player: %s"), *(playerTank->GetName()));
	}
}
ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerPawn) { return nullptr; }
	return Cast<ATank>(playerPawn);
}



