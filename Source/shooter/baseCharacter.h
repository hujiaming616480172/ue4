// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "baseCharacter.generated.h"

UCLASS(Blueprintable)
class SHOOTER_API AbaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	//make a health  property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;
	//make an isdead property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;

	//calculate death function(helper)
	virtual void CalculateDead();
	//calculate health function
	UFUNCTION(BlueprintCallable, Category = "Base Character" )
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	//edtior centric code for changing properties
	virtual void PostEditChangeProperty(FPropertyChangedEvent&PropertyChangedEvent)
		override;
#endif 
public:
	// Sets default values for this character's properties
	AbaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
