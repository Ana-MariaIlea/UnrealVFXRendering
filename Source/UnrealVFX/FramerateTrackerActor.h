// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"

#include "FramerateTrackerActor.generated.h"

USTRUCT(BlueprintType)
struct FFramerateTrackerStructure : public FTableRowBase
{
	GENERATED_BODY()

		//~ The following member variable will be accessible by Blueprint Graphs:
		// This is the tooltip for our test variable.
	UPROPERTY(EditAnywhere)
		FString LoopBehavior;
	UPROPERTY(EditAnywhere)
		int NumberOfSystems;
	UPROPERTY(EditAnywhere)
		float Seconds;
	UPROPERTY(EditAnywhere)
		float Framerate;

	FFramerateTrackerStructure() {

	}
};

UCLASS()
class UNREALVFX_API AFramerateTrackerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFramerateTrackerActor();

	UPROPERTY(EditAnywhere)
		UDataTable* FramerateDataTable;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int index;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TrackFramerate(FString loopBehavior, int numberOfSystems, float seconds, float framerate);
};
