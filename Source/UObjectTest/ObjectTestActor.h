// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObjects/VersatileUObject.h"
#include "ObjectTestActor.generated.h"

UCLASS()
class UOBJECTTEST_API AObjectTestActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	AObjectTestActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="ObjectTest")
	UVersatileUObject* TestObject();
};
