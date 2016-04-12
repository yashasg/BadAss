// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "SliderConsole.h"

// Sets default values
ASliderConsole::ASliderConsole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASliderConsole::BeginPlay()
{
	Super::BeginPlay();
	//emptyIndex = 15;
}

// Called every frame
void ASliderConsole::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ASliderConsole::CheckPattern() {
	/*if (sliderButtons.IsValidIndex(15) == false) {
		return;
	}*/
	for (int i = 0; i < 15; ++i) {
		if (sliderButtons[i]->currentPosition != sliderButtons[i]->correctPosition) {
			return false;
		}
	}
	return true;
}

bool ASliderConsole::MoveTile(int32 index) {
	// Check if this is next to the empty one
	if (sliderButtons[index]->currentPosition % 4 == 0) {
		if (sliderButtons[index]->currentPosition - 4 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition + 4 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition + 1 != sliderButtons[emptyIndex]->currentPosition) {
			return false;
		}
	}
	else if (sliderButtons[index]->currentPosition % 4 == 3) {
		if (sliderButtons[index]->currentPosition - 4 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition + 4 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition - 1 != sliderButtons[emptyIndex]->currentPosition) {
			return false;
		}
	}
	else {
		if (sliderButtons[index]->currentPosition - 4 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition + 4 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition - 1 != sliderButtons[emptyIndex]->currentPosition
			&& sliderButtons[index]->currentPosition + 1 != sliderButtons[emptyIndex]->currentPosition) {
			return false;
		}
	}

	// switch the two tiles.
	FVector tmpLoc = sliderButtons[emptyIndex]->GetActorLocation();
	sliderButtons[emptyIndex]->SetActorLocation( sliderButtons[index]->GetActorLocation() );
	sliderButtons[index]->SetActorLocation(tmpLoc);

	int32 tmpPos = sliderButtons[emptyIndex]->currentPosition;
	sliderButtons[emptyIndex]->currentPosition = sliderButtons[index]->currentPosition;
	sliderButtons[index]->currentPosition = tmpPos;



	//emptyIndex = index;

	/*ASliderButton* pTmpBtn = sliderButtons[emptyIndex];
	sliderButtons[emptyIndex] = sliderButtons[index];
	sliderButtons[index] = pTmpBtn;
	emptyIndex = index;*/

	return true;
}