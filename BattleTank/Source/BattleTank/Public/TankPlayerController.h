// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
    ATank* GetControlledTank() const;
   virtual void BeginPlay() override;
   virtual void Tick(float DeltaTime) override;
   void AimTowardsCrosshair();
   bool GetSightRayHitLocation(FVector& OutHitLocation) const;
   UPROPERTY(EditAnywhere)
       float CrosshaurXLocation = 0.5;
       float CrosshaurYLocation = 0.3333;
};
