// Fill out your copyright notice in the Description page of Project Settings.


#include "FramerateTrackerActor.h"

// Sets default values
AFramerateTrackerActor::AFramerateTrackerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFramerateTrackerActor::BeginPlay()
{
	Super::BeginPlay();
	
	index = 1;
}

// Called every frame
void AFramerateTrackerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFramerateTrackerActor::TrackFramerate(FString loopBehavior, int numberOfSystems, float seconds, float framerate)
{
	if(FramerateDataTable){

		FFramerateTrackerStructure NewStructure;
		NewStructure.LoopBehavior = loopBehavior;
		NewStructure.NumberOfSystems = numberOfSystems;
		NewStructure.Seconds = seconds;
		NewStructure.Framerate = framerate;

		FramerateDataTable->AddRow(FName(FString::Printf(TEXT("%d"), index)), NewStructure);
		index++;
	}
}

