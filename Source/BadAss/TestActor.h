// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "TestActor.generated.h"


UCLASS()
class BADASS_API ATestActor : public AActor,public IInteractable
{
	GENERATED_BODY()




public:	
	// Sets default values for this actor's properties
	ATestActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	

	// Inherited via IInteractable
	virtual void OnInteraction_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube")
	class UStaticMeshComponent* m_cube;

};
