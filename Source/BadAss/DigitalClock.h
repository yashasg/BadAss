// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DigitalClock.generated.h"

UCLASS()
class BADASS_API ADigitalClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADigitalClock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
private:
class UTextRenderComponent* m_TextTime;
class UStaticMeshComponent* m_Clock; 

	
	
};
