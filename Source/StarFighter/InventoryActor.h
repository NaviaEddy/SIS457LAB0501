// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInventoryActor();

	// Llamado a cada cuadro
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Atributos
	float Velocidad;
	int Vidas;
	int Armamento;
	float x;
	float vc;
	bool noContenido;

	
	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);

	// Destruye las capsulas
	void DestruyeCapsula();

};
