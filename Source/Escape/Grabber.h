// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far the player can reach to grab things
	UPROPERTY(EditAnywhere)
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Finds PhysicsHandleComponent and assigns it to variable PhysicsHandle, prints error message if can't find the component
	void GetPhysicsHandleComponent();

	// Looks for input component and binds 'grab' and 'release' actions
	void SetupInputComponent();

	// Ray-cast and grab what is in reach
	void Grab();

	// Called when grab is released
	void Release();

	FHitResult GetFirstPhysicsBodyInReach() const;
	FVector GetReachLineEnd() const;
	FVector GetReachLineStart() const;
};
