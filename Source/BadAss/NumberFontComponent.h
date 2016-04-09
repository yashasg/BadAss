// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "NumberFontComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BADASS_API UNumberFontComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNumberFontComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	//array to strore 3dModel of Numbers
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Digital Clock")
	class UStaticMeshComponent* m_numberArray[10];

	bool AddToArray(class UStaticMeshComponent* i_symbol, int i_Position);

		
	
};
