// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"
#include "Components/TextRenderComponent.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Green, text)

// Sets default values
AInventoryActor::AInventoryActor()
{
	PrimaryActorTick.bCanEverTick = true;
	// Referencia a malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
	GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetRelativeScale3D_Direct(FVector(0.5f, 1.25f, 0.5f));
	SetActorEnableCollision(true);

	x = 0.0f;
	vc = 200;
	noContenido = true;


}

// Called when the game starts or when spawned
void AInventoryActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AInventoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Creo la direccion y el vector movimiento
	const FVector MoveDirection = FVector(-x, 0.f, 0.f).GetClampedToMaxSize(1.0f);
	const FVector Movement = MoveDirection * vc * DeltaTime;
	const FRotator Rotation = Movement.Rotation();
	FHitResult Hit(1.f);
	x += 0.01;
	// Mueve la malla
	RootComponent->MoveComponent(Movement, Rotation, true, &Hit);
}

void AInventoryActor::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	noContenido = false;
}

void AInventoryActor::PutDown(FTransform TargetLocation)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
	vc = 0.f;
}

void AInventoryActor::DestruyeCapsula()
{
	// Si la capsula no esta contenidda sera destruida despues de cierto tiempo
	if (noContenido) {
		Destroy();
	}
}
