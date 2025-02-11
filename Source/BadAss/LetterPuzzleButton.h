// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LetterPuzzleButton.generated.h"

UCLASS()
class BADASS_API ALetterPuzzleButton : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleButtonProperties")
	FString theLetter;
	// Sets default values for this actor's properties
	ALetterPuzzleButton();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
