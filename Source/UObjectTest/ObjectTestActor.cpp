// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectTestActor.h"

// Sets default values
AObjectTestActor::AObjectTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UVersatileUObject* AObjectTestActor::TestObject()
{
	UVersatileUObject* TestObj=NewObject<UVersatileUObject>();
	return TestObj;
}

