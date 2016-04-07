// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "DigitalClock.h"


// Sets default values
ADigitalClock::ADigitalClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADigitalClock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADigitalClock::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

