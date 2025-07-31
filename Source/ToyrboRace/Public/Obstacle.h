// Obstacle.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class TOYRBORACE_API AObstacle : public AActor
{
    GENERATED_BODY()

public:
    AObstacle();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Obstacle")
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, Category = "Obstacle")
    float KnockbackStrength = 1000.0f;

    UFUNCTION()
    void OnObstacleHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
