// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "MyCharacterEcholocation.h"

// Sets default values
AMyCharacterEcholocation::AMyCharacterEcholocation()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyCharacterEcholocation::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this,
		&AMyCharacterEcholocation::Echolocate,
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

void AMyCharacterEcholocation::Echolocate()
{
	// We have actors to light up in LocatedObjects
	TArray<AActor*> LocatedObjects;
	GetOverlappingActors(LocatedObjects);
	int NumOfActors = LocatedObjects.Num();

	PrintOnScreen(NumOfActors);

	for (int i = 0; i < NumOfActors; i++)
	{
		// PROBLEM: On second pass where this statement is true -> will crash
		if (ObjectToDupeMap.Contains(LocatedObjects[i]))
		{
			ObjectToDupeMap[LocatedObjects[i]] = nullptr;
			//delete ObjectToDupeMap[LocatedObjects[i]];
		}
		else
		{
			ObjectToDupeMap.Add(LocatedObjects[i], nullptr);
		}

		// Spawn a dupe of the actor
		FActorSpawnParameters spawnParams = FActorSpawnParameters();
		spawnParams.Template = LocatedObjects[i];  // LocatedObjects[i] isn't an actor???
		ObjectToDupeMap[LocatedObjects[i]] = GetWorld()->SpawnActor<AActor>(LocatedObjects[i]->GetActorLocation(), LocatedObjects[i]->GetActorRotation(), spawnParams);

		// Change to lit mesh
		//ObjectToDupeMap[LocatedObjects[i]]->GetComponentByClass<UStaticMeshComponent>()->SetMaterial(0, LitMaterial); // Can't get 
	}
}

void AMyCharacterEcholocation::PrintOnScreen(const int x) const
{
	// Debug print
	UE_LOG(LogTemp, Warning, TEXT("Num: %i"), x);
}

