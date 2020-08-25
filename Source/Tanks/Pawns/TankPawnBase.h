// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"

#include "TankPawnBase.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;
class UCameraComponent;

UCLASS()
class TANKS_API ATankPawnBase : public APawn
{
    GENERATED_BODY()

public:
    ATankPawnBase();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision", Meta = (AllowPrivateAccess = "True"))
    UCapsuleComponent *SceneRoot;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Visuals", Meta = (AllowPrivateAccess = "True"))
    UStaticMeshComponent *BaseMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Visuals", Meta = (AllowPrivateAccess = "True"))
    UStaticMeshComponent *TurretMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera rig", Meta = (AllowPrivateAccess = "True"))
    USpringArmComponent *CameraSpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera rig", Meta = (AllowPrivateAccess = "True"))
    UCameraComponent *CameraComponent;

protected:
    virtual void BeginPlay() override;

};
