// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "DigitalClock.generated.h"

UCLASS()
class BADASS_API ADigitalClock : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADigitalClock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void ADigitalClock::OnInteraction_Implementation();
UPROPERTY(EditAnyWhere,BlueprintReadWrite,Category="Digital Clock")
bool m_Editable;
UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Digital Clock")
uint8  m_Hours;
UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Digital Clock")
uint8  m_Minutes;
UFUNCTION(BlueprintCallable, Category = "Digital Clock")
void UpdateTime(class UTextRenderComponent* i_Minutes, class UTextRenderComponent* i_Seconds);
UFUNCTION(BlueprintCallable, Category = "Digital Clock")
void setTextHour(class UTextRenderComponent* i_TextHour);

UFUNCTION(BlueprintCallable, Category = "Digital Clock")
void setTextMinute(class UTextRenderComponent* i_TextMin);
UFUNCTION(BlueprintCallable, Category = "Digital Clock")
bool checkTimeEqual(ADigitalClock* i_other);



private:
	void setTextofTime();
	void checkConstraints();
	class UTextRenderComponent* m_TextHour;
	class UTextRenderComponent* m_TextMin;

uint8_t  m_Seconds;

	
	
};
