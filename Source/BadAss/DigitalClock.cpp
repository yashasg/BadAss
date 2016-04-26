// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "DigitalClock.h"
#include <string>
#include <stdlib.h>


// Sets default values
ADigitalClock::ADigitalClock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_Hours = 11;
	m_Minutes = std::rand() % 60;

}

// Called when the game starts or when spawned
void ADigitalClock::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADigitalClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADigitalClock::OnInteraction_Implementation()
{
	if (m_Editable) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("in Digital Clock Interaction"));
		m_Minutes += 1;
		checkConstraints();
		setTextofTime();

	}
}


void ADigitalClock::UpdateTime(UTextRenderComponent * i_Minutes, UTextRenderComponent * i_Seconds)
{
	if (!m_Editable) {
		m_Seconds += 1;

		checkConstraints();
		i_Minutes->SetText(FText::AsNumber(m_Hours));
		i_Seconds->SetText(FText::AsNumber(m_Minutes));
	}
}

void ADigitalClock::setTextHour(UTextRenderComponent * i_TextHour)
{
	m_TextHour = i_TextHour;
	m_TextHour->SetText(FText::AsNumber(m_Hours));
}

void ADigitalClock::clickInteracted(float i_y)
{
	if(i_y> -10.0f)
	m_Minutes += 1;

	else
	{
		m_Hours += 1;
	}
	checkConstraints();
	setTextofTime();
}

void ADigitalClock::setTextMinute(UTextRenderComponent * i_TextMin)
{
	m_TextMin = i_TextMin;
	m_TextMin->SetText(FText::AsNumber(m_Minutes));
}

bool ADigitalClock::checkTimeEqual(ADigitalClock * i_other)
{
	if (m_Hours == i_other->m_Hours && m_Minutes == i_other->m_Minutes)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Equal Time"));
		return true;
	}
	else
		return false;
}

void ADigitalClock::setTextofTime()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("in Set Text of Time"));
	m_TextMin->SetText(FText::AsNumber(m_Minutes));
	m_TextHour->SetText(FText::AsNumber(m_Hours));
}

void ADigitalClock::checkConstraints()
{
	if (m_Seconds == 60) {
		m_Minutes += 1;
		m_Seconds = 0;
	}
	if (m_Minutes == 60) {
	m_Hours += 1;
	m_Minutes = 0;
	}
	if (m_Hours == 13) {
		m_Hours = 1;
	}
}

