// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma.h"

ACapsulaArma::ACapsulaArma()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/OrangeMaterial.OrangeMaterial'"));
	GetStaticMeshComponent()->SetMaterial(0, MaterialAsset.Object);
}

