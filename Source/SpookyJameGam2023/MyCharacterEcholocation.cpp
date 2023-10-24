// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterEcholocation.h"

// Sets default values
AMyCharacterEcholocation::AMyCharacterEcholocation()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Delay = 3.0f;
}

// Called when the game starts or when spawned
void AMyCharacterEcholocation::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this,
		&AMyCharacterEcholocation::PrintOnScreen,
		Delay, true);
}

// Called every frame
void AMyCharacterEcholocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterEcholocation::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacterEcholocation::PrintOnScreen()
{
	// We have actors to light up in LocatedObjects
	GetOverlappingActors(LocatedObjects);
	int32 NumOfActors = LocatedObjects.Num();

	// Debug print
	UE_LOG(LogTemp, Warning, TEXT("Num: %i"), NumOfActors);

	if (NumOfActors > 0)
	{
		for (int i = 0; i < NumOfActors; i++)
		{
			// Spawn a dupe of each actor with the lit-up mesh

			// Keep them on-screen for Delay minus an offset # of seconds

			// Destroy lit-up actors
		}
	}
}

