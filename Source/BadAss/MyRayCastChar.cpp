// Fill out your copyright notice in the Description page of Project Settings.

#include "BadAss.h"
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
	InputComponent->BindAction("Fire", IE_Pressed, this, &AMyRayCastChar::OnFire);

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

void AMyRayCastChar::OnFire()
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Left click Caught"));


	if(Controller && Controller->IsLocalPlayerController()) // we check the controller becouse we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector CamLoc;
		FRotator CamRot;
	
		Controller->GetPlayerViewPoint(CamLoc, CamRot); // Get the camera position and rotation
		const FVector StartTrace = CamLoc; // trace start is the camera location
		const FVector Direction = CamRot.Vector();
		const FVector EndTrace = StartTrace + Direction *200; // and trace end is the camera location + an offset in the direction you are looking, the 200 is the distance at wich it checks
	
		// Perform trace to retrieve hit info
		FCollisionQueryParams TraceParams(FName(TEXT("WeaponTrace")),true,this);
		TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		GetWorld()->LineTraceSingle(Hit, StartTrace, EndTrace, ECC_Camera, TraceParams); // simple trace function
		AActor* destroyed = Hit.GetActor();
		//destroyed->


		/*IUsable* usable = InterfaceCast<IUsable>(Hit.GetActor()); // we cast the hit actor to the IUsable interface
		if(usable) // we are looking to a usable object
		{
			UseFocus = usable; // as the actor under crosshairs is a usable actor, we store it for the hud.
		}
		else
		{
			UseFocus = NULL; // nothing, so we set the UseFocus pointer to NULL, so it wont give problems
		}*/
	}
	}

}

