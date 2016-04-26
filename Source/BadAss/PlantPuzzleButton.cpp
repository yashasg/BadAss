// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "PlantPuzzleButton.h"


// Sets default values
APlantPuzzleButton::APlantPuzzleButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlantPuzzleButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlantPuzzleButton::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APlantPuzzleButton::TurnOnOff() {
	m_isOn = !m_isOn;
	return;
}
void APlantPuzzleButton::TurnOff() {
	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(TEXT("ApplyOffMat"), ar, NULL, true);
	m_isOn = false;
	return;
}
void APlantPuzzleButton::TurnOn() {

	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(TEXT("ApplyOnMat"), ar, NULL, true);
	m_isOn = true;
	return;
}
bool APlantPuzzleButton::IsOn() {
	return m_isOn;
}