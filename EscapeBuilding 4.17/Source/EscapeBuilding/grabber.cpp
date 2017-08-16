// Fill out your copyright notice in the Description page of Project Settings.

#include "grabber.h"

#define OUT
// Sets default values for this component's properties
Ugrabber::Ugrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Ugrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Ugrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Player = GetWorld()->GetFirstPlayerController();

	Player->GetActorEyesViewPoint(OUT vec, OUT rot);

	FVector LineTraceEnd = vec + rot.Vector() * Reach;

	DrawDebugLine(GetWorld(),
		vec,
		LineTraceEnd,
		FColor(255.f,0.f,0.f),
		false,
		0.f,
		0.f,
		10.f
	);

	// ...
}

