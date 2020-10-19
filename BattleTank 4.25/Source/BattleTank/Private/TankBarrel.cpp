// Fill out your copyright notice in the Description page of Project Settings.

//#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation,minElevationDegrees,MaxElevationDegrees);
	SetRelativeRotation(FRotator(RawNewElevation,0,0));

}