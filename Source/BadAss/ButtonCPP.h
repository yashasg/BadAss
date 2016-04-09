// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "IInteractable.h"
#include "ButtonCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BADASS_API UButtonCPP : public UActorComponent,public IInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UButtonCPP();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	

	// Inherited via IInteractable
	virtual void OnInteraction_Implementation();

};
