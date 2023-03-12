// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeathMatchProjectile.h"
#include "GameFramework/GameModeBase.h"
#include "DeathMatchGameMode.generated.h"

UCLASS(minimalapi)
class ADeathMatchGameMode : public AGameModeBase {
  GENERATED_BODY()

 public:
  ADeathMatchGameMode();

  virtual void Tick(float DeltaTime) override;
  int32 KillsNum;

  void DeleteEnemy();

 protected:
  UPROPERTY(EditAnywhere)
  TSubclassOf<class AEnemyActor> EnemyActor;

  virtual void BeginPlay() override;

  UFUNCTION(BlueprintCallable, Category = "Enemy")
  void SpawnEnemy();

  UPROPERTY(BlueprintReadWrite, Category = "Enemy")
  int32 CountOfEnemy;

 private:
  TArray<FVector> EnemyPosition;

  bool CheckPosition(int32 X, int32 Y);

  TArray<class AActor*> Enemies;

};
