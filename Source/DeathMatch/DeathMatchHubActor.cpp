// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathMatchHubActor.h"

#include "Engine/World.h"

using namespace std;

// Sets default values
ADeathMatchHubActor::ADeathMatchHubActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADeathMatchHubActor::BeginPlay() {
  Super::BeginPlay();

  UWorld* World = GetWorld();

  if (World) {
    FVector PlayerLocation =
        GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
    int32 X =
        FMath::RandRange(PlayerLocation.X - 1500, PlayerLocation.X + 1500);
    int32 Y =
        FMath::RandRange(PlayerLocation.Y - 1500, PlayerLocation.Y + 1500);
    for (int i = 0; i < 15; i++) {
      const FVector Vector(X, Y, 200);
      EnemyPosition.Add(Vector);
      const FRotator Rotator(0, 0, 0);

      World->SpawnActor(EnemyActor, &Vector, &Rotator);

      do {
        X = FMath::RandRange(PlayerLocation.X - 1500, PlayerLocation.X + 1500);
        Y = FMath::RandRange(PlayerLocation.Y - 1500, PlayerLocation.Y + 1500);
      } while (!CheckPosition(X, Y));
    }
  }
}

// Called every frame
void ADeathMatchHubActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

bool ADeathMatchHubActor::CheckPosition(int32 X, int32 Y) {
  for (FVector& Vector : EnemyPosition) {
    if (FMath::Abs(Vector.X - X) <= 200 && FMath::Abs(Vector.Y - Y) <= 200)
      return false;
  }
  return true;
}
