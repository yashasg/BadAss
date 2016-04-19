// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "LetterPuzzleConsole.h"


bool ALetterPuzzleConsole::UpdateTheWord(FString i_newLetter)
{
	if (theWord == "Wrong Password!") {
		theWord = "";
	}
	theWord += i_newLetter;
	if (theWord.Len() >= theCorrectWord.Len()) {
		if (theWord == theCorrectWord) {
			theWord = "You win!";
			return true;
		}
		else {
			theWord = "Wrong Password!";
		}
	}
	return false;
}

void ALetterPuzzleConsole::ChangeSolution()
{
	// Changed the corretWord
	theCorrectWord = theCorrectWords[rand() % theCorrectWords.Num()]; FOutputDeviceNull ar;
	for (int i = 0; i < theCorrectWord.Len(); ++i) {
		for (int j = 0; j < solutionButtons.Num(); ++j) {
			if (solutionButtons[j]->theLetter[0] == theCorrectWord[i]) {
				solutionButtons[j]->CallFunctionByNameWithArguments(TEXT("ChangeToRed"), ar, NULL, true);
			}
			else {
				solutionButtons[j]->CallFunctionByNameWithArguments(TEXT("ChangeToBlue"), ar, NULL, true);
			}
		}
	}
}

// Sets default values
ALetterPuzzleConsole::ALetterPuzzleConsole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALetterPuzzleConsole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALetterPuzzleConsole::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

