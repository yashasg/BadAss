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
	
}

// Called every frame
void ASliderConsole::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

