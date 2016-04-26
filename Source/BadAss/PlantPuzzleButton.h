// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlantPuzzleButton.generated.h"

UCLASS()
class BADASS_API APlantPuzzleButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantPuzzleButton();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
		void TurnOnOff(); 
	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
		void TurnOff();
	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
		void TurnOn();

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
	bool IsOn();
private:
	bool m_isOn;
};
