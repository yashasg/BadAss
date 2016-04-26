// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "PlantPuzzleConsole.h"


// Sets default values
APlantPuzzleConsole::APlantPuzzleConsole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
/*
	if (solution.Num() <= 0) {
		m_indexProgress = -1;
	}
	else {*/
		m_indexProgress = 0;
	/*}*/
}

// Called when the game starts or when spawned
void APlantPuzzleConsole::BeginPlay()
{
	Super::BeginPlay();
	
	solved = false;
	ResetButtons();
}

// Called every frame
void APlantPuzzleConsole::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool APlantPuzzleConsole::ClickButtonAt(int32 i_indexButton) {

	if (solved) {
		return false;
	}
	if (solution[m_indexProgress] != i_indexButton) {
		// start over
		m_indexProgress = 0;
		ResetButtons();
		return false;
	}

	// Turn on or turn of the light
	buttons[i_indexButton]->TurnOn();

	m_indexProgress++;

	if (m_indexProgress == solution.Num()) {
		TurnOnAllButtons();
		solved = true;
		return true;
	}

	return false;
}

void APlantPuzzleConsole::ResetButtons() {
	for (int i = 0; i < 25; ++i) {
		buttons[i]->TurnOff();
	}
}

void APlantPuzzleConsole::TurnOnAllButtons() {
	for (int i = 0; i < 25; ++i) {
		buttons[i]->TurnOn();
	}
}