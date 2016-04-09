// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "TestActor.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_cube = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("Cube"));
	m_cube->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATestActor::OnInteraction_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("in OnInteraction"));
	FVector fv(100.0f, 0.0f, 0.0f);
	m_cube->AddForce(fv);
}