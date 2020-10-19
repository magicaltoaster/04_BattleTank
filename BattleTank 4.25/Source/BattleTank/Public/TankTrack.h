// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * tanktrack is used to set max driving force and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category = Input)
	void SetThrottle(float Throttle);
	//max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000; // 40 ton tank 1g acceleration
};
