// Fill out your copyright notice in the Description page of Project Settings.
///TODO fix this 
//#include "BattleTank.h"
#include "../Public/Tank.h"
#include "TankPlayerController.h"

//tick
	//super
	//aimtowardscrosshair();
void ATankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("pC TIcker"));
}
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
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
void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HITLOCATION %s"), *HitLocation.ToString());
	}


}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation)const {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshaurXLocation, ViewportSizeY * CrosshaurYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("SCreen location %s"), *ScreenLocation.ToString());
	OutHitLocation = FVector(1.f);
	return true;
}