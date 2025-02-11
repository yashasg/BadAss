// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyRayCastChar.generated.h"

UCLASS()
class BADASS_API AMyRayCastChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyRayCastChar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//handles moving forward/backward
	UFUNCTION()
		void MoveForward(float Val);
	//handles strafing
	UFUNCTION()
		void MoveRight(float Val);

	UFUNCTION(BlueprintCallable, Category = "Character")
	bool DealWithActor(FHitResult i_result);


	
	
};
