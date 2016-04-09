// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
#include "IInteractable.h"
#include "MyRayCastChar.h"


// Sets default values
AMyRayCastChar::AMyRayCastChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyRayCastChar::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using FPSCharacter!"));
	}
	
}

// Called every frame
void AMyRayCastChar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyRayCastChar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	// set up gameplay key bindings
	InputComponent->BindAxis("MoveForward", this, &AMyRayCastChar::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyRayCastChar::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMyRayCastChar::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMyRayCastChar::AddControllerPitchInput);

}
void AMyRayCastChar::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}
void AMyRayCastChar::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

bool AMyRayCastChar::DealWithActor(FHitResult  i_result)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("in Deal with Actor"));
	IInteractable* interactedObject = InterfaceCast<IInteractable>(i_result.GetActor());
	if (interactedObject)
		interactedObject->OnInteraction_Implementation();
	return true;
}

