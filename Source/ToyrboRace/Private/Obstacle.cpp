// Obstacle.cpp
#include "Obstacle.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AObstacle::AObstacle()
{
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
    RootComponent = Mesh;
    Mesh->SetSimulatePhysics(true);
    Mesh->SetNotifyRigidBodyCollision(true);
    Mesh->OnComponentHit.AddDynamic(this, &AObstacle::OnObstacleHit);
}

void AObstacle::BeginPlay()
{
    Super::BeginPlay();
}

void AObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AObstacle::OnObstacleHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (ACharacter* Player = Cast<ACharacter>(OtherActor))
    {
        FVector KnockbackDirection = Player->GetActorLocation() - GetActorLocation();
        KnockbackDirection.Normalize();

        Player->LaunchCharacter(KnockbackDirection * KnockbackStrength, true, true);
    }
}
