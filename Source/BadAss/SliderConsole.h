// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SliderButton.h"
#include "SliderConsole.generated.h"

UCLASS()
class BADASS_API ASliderConsole : public AActor
{
	GENERATED_BODY()

	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	//FString str;
	TArray<ASliderButton*> sliderButtons;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	int32 emptyIndex;

	// Sets default values for this actor's properties
	ASliderConsole();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
	bool CheckPattern();
	
	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
		bool MoveTile(int32 index);
};
