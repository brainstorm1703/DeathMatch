// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyActor.h"
#include "GameFramework/Actor.h"
#include "DeathMatchHubActor.generated.h"

UCLASS()
class DEATHMATCH_API ADeathMatchHubActor : public AActor {
  GENERATED_BODY()

 public:
  // Sets default values for this actor's properties
  ADeathMatchHubActor();

 protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  UPROPERTY(EditAnywhere)
  TSubclassOf<AEnemyActor> EnemyActor;

 public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

 private:
  TArray<FVector> EnemyPosition;

  bool CheckPosition(int32 X, int32 Y);
};
