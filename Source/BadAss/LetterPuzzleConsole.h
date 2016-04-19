// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LetterPuzzleButton.h"
#include "LetterPuzzleConsole.generated.h"

UCLASS()
class BADASS_API ALetterPuzzleConsole : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	FString theWord;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
		TArray<FString> theCorrectWords; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
		FString theCorrectWord;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	TArray<ALetterPuzzleButton*> solutionButtons;

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
	bool UpdateTheWord(FString i_newLetter);

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
		void ChangeSolution();

	// Sets default values for this actor's properties
	ALetterPuzzleConsole();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
