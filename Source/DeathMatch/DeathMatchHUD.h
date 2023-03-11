// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DeathMatchHUD.generated.h"

UCLASS()
class ADeathMatchHUD : public AHUD
{
	GENERATED_BODY()

public:
	ADeathMatchHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

