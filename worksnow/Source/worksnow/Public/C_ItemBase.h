// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_ItemBase.generated.h"

UENUM(BlueprintType)
enum class FireModes : uint8 {
	SINGLE = 0 UMETA(DisplayName = "SINGLE"),
	BURST = 1  UMETA(DisplayName = "BURST"),
	AUTOMATIC = 2     UMETA(DisplayName = "AUTOMATIC"),
};

USTRUCT(BlueprintType)
struct FS_MagazineBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;
};

USTRUCT(BlueprintType)
struct FS_FirearmBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		struct FS_MagazineBase MagazineType;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		//TArray<UStruct FS_AmmoBase> AmmoTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		float Recoil;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		float SpreadValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		bool Spread;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		int64 BulletsPerShot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		TEnumAsByte <FireModes> FireMode;

};

USTRUCT(BlueprintType)
struct FS_AmmoBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;
};

USTRUCT(BlueprintType)
struct FS_SpawnPoint
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;
};

USTRUCT(BlueprintType)
struct FS_InventorySlot
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;
};

USTRUCT(BlueprintType)
struct FS_ItemBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool Container;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool Pickupable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool Equippable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		UTexture2D* Icon;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		//class C_ItemBase* ClassRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		struct FS_FirearmBase FirearmStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		class AActor* WorldActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool CanUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool ConsumedOnUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool HasQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		float MaxQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		float CurrentQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		int64 QuickBarNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		struct FS_SpawnPoint SpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		struct FS_InventorySlot InventorySlot;

};

UCLASS()
class WORKSNOW_API AC_ItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	FS_ItemBase ItemInfo;
	AC_ItemBase()
	//{
		//FS_ItemBase ItemInfo;
	//};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
