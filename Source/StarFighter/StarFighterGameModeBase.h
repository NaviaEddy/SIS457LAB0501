// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarFighterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AStarFighterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	AStarFighterGameModeBase();

private:

	class ACapsulaVelocidad* capsulaV1;
	class ACapsulaVelocidad* capsulaV2;
	class ACapsulaVelocidad* capsulaV3;
	class ACapsulaVida* capsulaVi1;
	class ACapsulaVida* capsulaVi2;
	class ACapsulaVida* capsulaVi3;
	class ACapsulaArma* capsulaA1;
	class ACapsulaArma* capsulaA2;
	class ACapsulaArma* capsulaA3;
	
};
