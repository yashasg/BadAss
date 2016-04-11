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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//FString str;
	TArray<ASliderButton*> buttons;

	// Sets default values for this actor's properties
	ASliderConsole();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
