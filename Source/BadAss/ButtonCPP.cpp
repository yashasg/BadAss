// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "ButtonCPP.h"


// Sets default values for this component's properties
UButtonCPP::UButtonCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UButtonCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UButtonCPP::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UButtonCPP::OnInteraction_Implementation()
{
}

