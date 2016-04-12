// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LetterPuzzleConsole.generated.h"

UCLASS()
class BADASS_API ALetterPuzzleConsole : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	FString theWord;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	FString theCorrectWord;

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
	bool UpdateTheWord(FString i_newLetter);

	// Sets default values for this actor's properties
	ALetterPuzzleConsole();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
