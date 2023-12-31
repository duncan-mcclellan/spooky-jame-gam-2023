// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterEcholocation.generated.h"

UCLASS()
class SPOOKYJAMEGAM2023_API AMyCharacterEcholocation : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterEcholocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Echolocate();

	void PrintOnScreen(const int) const;

	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Delay = 3.0f;

	TMap<AActor*, AActor*> ObjectToDupeMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial* LitMaterial;
};
