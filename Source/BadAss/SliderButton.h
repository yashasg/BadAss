// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "SliderButton.generated.h"

UCLASS()
class BADASS_API ASliderButton : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	int32 correctPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	int32 currentPosition;

	// Sets default values for this actor's properties
	ASliderButton();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void OnInteraction_Implementation();
};
