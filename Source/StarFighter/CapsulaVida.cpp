// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida.h"

ACapsulaVida::ACapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/TwinStick/Meshes/BaseMaterial.BaseMaterial'"));
	GetStaticMeshComponent()->SetMaterial(0, MaterialAsset.Object);
}