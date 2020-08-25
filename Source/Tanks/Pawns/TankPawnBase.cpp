// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawnBase.h"
#include "Camera/CameraComponent.h"

#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

ATankPawnBase::ATankPawnBase()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;
    
    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    BaseMesh->SetupAttachment(RootComponent);

    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
    TurretMesh->SetupAttachment(BaseMesh);

    CameraSpringArmComponent =CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera SpringArm"));
    CameraSpringArmComponent->SetupAttachment(RootComponent);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    CameraComponent->SetupAttachment(CameraSpringArmComponent);
}

void ATankPawnBase::BeginPlay()
{
    Super::BeginPlay();
}

void ATankPawnBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATankPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
