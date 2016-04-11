// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "NumberFontComponent.h"


// Sets default values for this component's properties
UNumberFontComponent::UNumberFontComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	/*m_numberArray[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT(""));
	m_numberArray[0]->SetStaticMesh(MeshObj.Object);*/

	// ...
}


// Called when the game starts
void UNumberFontComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNumberFontComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

bool UNumberFontComponent::AddToArray(UStaticMeshComponent * i_symbol, uint8 i_Position)
{
	m_numberArray[i_Position] = i_symbol;
	return true;
}

UStaticMeshComponent * UNumberFontComponent::getModel(uint8 i_Position)
{
	return nullptr;
}

