// Fill out your copyright notice in the Description page of Project Settings.

#include "shooter.h"
#include "baseCharacter.h"


// Sets default values
AbaseCharacter::AbaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AbaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AbaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AbaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


//Implement CalculateHealth
void AbaseCharacter::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}


//Implement CalculateDead

VOID AbaseCharacter::CalculateDead()
{
	if (Health <= 0)
		isDead = true;
	else
		isDead = false;
}

//Implement PostEditChangeProperty
#if WITH_EDITOR
void AbaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	Health = 100;
	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();

}
#endif
