// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathMatchGameMode.h"

#include "DeathMatchCharacter.h"
#include "DeathMatchHUD.h"
#include "DeathMatchProjectile.h"
#include "EnemyActor.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

ADeathMatchGameMode::ADeathMatchGameMode() : Super() {
  // set default pawn class to our Blueprinted character
  static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(
      TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
  DefaultPawnClass = PlayerPawnClassFinder.Class;

  // use our custom HUD class
  HUDClass = ADeathMatchHUD::StaticClass();
}

void ADeathMatchGameMode::BeginPlay() {
  Super::BeginPlay();
  ADeathMatchGameMode::CountOfEnemy = 15;

  ADeathMatchGameMode::KillsNum = 0;

  ADeathMatchGameMode::SpawnEnemy();
}

void ADeathMatchGameMode::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
}

void ADeathMatchGameMode::DeleteEnemy() {
  for (int i = 0; i < ADeathMatchGameMode::Enemies.Num(); i++) {
    if (ADeathMatchGameMode::Enemies[i])
      ADeathMatchGameMode::Enemies[i]->Destroy();
  }
  ADeathMatchGameMode::Enemies.Empty();

  ADeathMatchGameMode::CountOfEnemy *= 1.1;

  ADeathMatchGameMode::KillsNum = 0;

  ADeathMatchGameMode::SpawnEnemy();
}

bool ADeathMatchGameMode::CheckPosition(int32 X, int32 Y) {
  for (FVector& Vector : EnemyPosition) {
    if (FMath::Abs(Vector.X - X) <= 200 && FMath::Abs(Vector.Y - Y) <= 200)
      return false;
  }
  return true;
}

void ADeathMatchGameMode::SpawnEnemy() {
  UWorld* World = GetWorld();

  if (World) {
    FVector PlayerLocation =
        GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
    int32 X =
        FMath::RandRange(PlayerLocation.X - 1500, PlayerLocation.X + 1500);
    int32 Y =
        FMath::RandRange(PlayerLocation.Y - 1500, PlayerLocation.Y + 1500);
    for (int i = 0; i < ADeathMatchGameMode::CountOfEnemy; i++) {
      const FVector Vector(X, Y, 200);
      EnemyPosition.Add(Vector);
      const FRotator Rotator(0, 0, 0);

      Enemies.Add(World->SpawnActor(EnemyActor, &Vector, &Rotator));

      do {
        X = FMath::RandRange(PlayerLocation.X - 1500, PlayerLocation.X + 1500);
        Y = FMath::RandRange(PlayerLocation.Y - 1500, PlayerLocation.Y + 1500);
      } while (!CheckPosition(X, Y));
    }
  }
}
