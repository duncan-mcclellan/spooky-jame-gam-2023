// Fill out your copyright notice in the Description page of Project Settings.


#include "Echolocation.h"

// Sets default values
AEcholocation::AEcholocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Delay = 1.0f;
}

// Called when the game starts or when spawned
void AEcholocation::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this,
		&AEcholocation::PrintOnScreen,
		Delay, true);
}

// Called every frame
void AEcholocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEcholocation::PrintOnScreen()
{
	UE_LOG(LogTemp, Warning, TEXT("We're Printing"));
}