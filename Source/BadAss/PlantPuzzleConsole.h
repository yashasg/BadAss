// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlantPuzzleButton.h"
#include "PlantPuzzleConsole.generated.h"

UCLASS()
class BADASS_API APlantPuzzleConsole : public AActor
{
	GENERATED_BODY()

	int32 m_indexProgress;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	TArray<APlantPuzzleButton*> buttons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
	TArray<int32> solution;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PuzzleConsoleProperties")
		bool solved;


	// Sets default values for this actor's properties
	APlantPuzzleConsole();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "PuzzleConsoleFunctions")
	bool ClickButtonAt(int32 i_indexButton);
	
private:
	void ResetButtons();
	void TurnOnAllButtons();
	void RandomButtons(int32 i_indexProgress);
};
