// Fill out your copyright notice in the Description page of Project Settings.
///TODO fix this 
//#include "BattleTank.h"
#include "../Public/Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	auto ControlledTank = ATankPlayerController::GetControlledTank();
	if (ControlledTank==nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Controller posssessing: %s"), *(ControlledTank->GetName()));
	}
}
	


ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

