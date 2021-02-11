// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_Base.generated.h"

UENUM(BlueprintType)
enum class E_FireModes : uint8 {
	SINGLE = 0 UMETA(DisplayName = "SINGLE"),
	BURST = 1  UMETA(DisplayName = "BURST"),
	AUTOMATIC = 2     UMETA(DisplayName = "AUTOMATIC"),
	CHARGE = 3  UMETA(DisplayName = "CHARGE"),
	BEAM = 4     UMETA(DisplayName = "BEAM"),
};// consider moving to firearm base c++ class

UENUM(BlueprintType)
enum class E_FirearmTypes : uint8 {
	RIFLE = 0 UMETA(DisplayName = "Rifle"),
	PISTOL = 1  UMETA(DisplayName = "PISTOL"),
	MELEE = 2     UMETA(DisplayName = "MELEE"),
};// consider moving to firearm base c++ class

UENUM(BlueprintType)
enum class E_InteractUIElements : uint8 {
	GENERIC = 0 UMETA(DisplayName = "GENERIC"),
	SEARCHABLE = 1  UMETA(DisplayName = "SEARCHABLE"),
	STATICINTERACTABLE = 2     UMETA(DisplayName = "STATICINTERACTABLE"),
	LOCKED = 2     UMETA(DisplayName = "LOCKED"),
};

UENUM(BlueprintType)
enum class E_ItemTiers : uint8 {
	COMMON = 0 UMETA(DisplayName = "COMMON"),
	UNCOMMON = 1  UMETA(DisplayName = "UNCOMMON"),
	RARE = 2     UMETA(DisplayName = "RARE"),
	UNIQUE = 3  UMETA(DisplayName = "UNIQUE"),
	EVENT = 4     UMETA(DisplayName = "EVENT"),
};// consider moving to spawnpoint c++ class

UENUM(BlueprintType)
enum class E_LootTypes : uint8 {
	NONE = 0 UMETA(DisplayName = "NONE"),
	MEDICAL = 1  UMETA(DisplayName = "MEDICAL"),
	AMMO = 2     UMETA(DisplayName = "AMMO"),
	WEAPONS = 3  UMETA(DisplayName = "WEAPONS"),
	FOOD = 4     UMETA(DisplayName = "FOOD"),
	RESOURCE = 5     UMETA(DisplayName = "RESOURCE"),
};// consider moving to spawnpoint c++ class

UENUM(BlueprintType)
enum class E_MonthNames : uint8 {
	JANUARY = 0 UMETA(DisplayName = "NONE"),
	FEBRUARY = 1  UMETA(DisplayName = "MEDICAL"),
	MARCH = 2     UMETA(DisplayName = "AMMO"),
	APRIL = 3  UMETA(DisplayName = "WEAPONS"),
	MAY = 4     UMETA(DisplayName = "FOOD"),
	JUNE = 5     UMETA(DisplayName = "RESOURCE"),
	JULY = 6 UMETA(DisplayName = "NONE"),
	AUGUST = 7  UMETA(DisplayName = "MEDICAL"),
	SEPTEMBER = 8     UMETA(DisplayName = "AMMO"),
	OCTOBER = 9  UMETA(DisplayName = "WEAPONS"),
	NOVEMBER = 10     UMETA(DisplayName = "FOOD"),
	DECEMBER = 11     UMETA(DisplayName = "RESOURCE"),
};  // consider moving to header related to weather/sky system

UENUM(BlueprintType)
enum class E_StartingClasses : uint8 {
	NONE = 0 UMETA(DisplayName = "NONE"),
	RUNNER = 1  UMETA(DisplayName = "RUNNER"),
	RANGER = 2     UMETA(DisplayName = "RANGER"),
	JUGGERNAUGHT = 3  UMETA(DisplayName = "JUGGERNAUGHT"),
	TECHIE = 4     UMETA(DisplayName = "TECHIE"),
	SURVIVALIST = 5     UMETA(DisplayName = "SURVIVALIST"),
};// consider moving to a place

UENUM(BlueprintType)
enum class E_StaticInteractableTypes : uint8 {
	DOOR = 0 UMETA(DisplayName = "DOOR"),
	TRIGGER = 1  UMETA(DisplayName = "TRIGGER"),
	ANIMATEDTRIGGER = 2     UMETA(DisplayName = "ANIMATEDTRIGGER"),
	STATION = 3  UMETA(DisplayName = "STATION"),
	LIGHT = 4     UMETA(DisplayName = "LIGHT"),
	MISC = 5     UMETA(DisplayName = "MISC"),
};// consider moving to StaticInteractables c++ class

UENUM(BlueprintType)
enum class E_AttachmentTypes : uint8 {
	NONE = 0 UMETA(DisplayName = "NONE"),
	SCOPE = 1  UMETA(DisplayName = "SCOPE"),
	GRIP = 2     UMETA(DisplayName = "GRIP"),
	TAC1 = 3  UMETA(DisplayName = "TAC1"),
	TAC2 = 4     UMETA(DisplayName = "TAC2"),
	MUZZLE = 5     UMETA(DisplayName = "MUZZLE"),
};// consider moving to weapon or attachmentbase c++ class

UENUM(BlueprintType)
enum class E_AmmoTypes : uint8 {
	PISTOL1 = 0 UMETA(DisplayName = "9mm"),
	PISTOL2 = 1  UMETA(DisplayName = "45acp"),
	SHOTGUN1 = 2     UMETA(DisplayName = "12gaPellets"),
	SHOTGUN2 = 3  UMETA(DisplayName = "12gaSlugs"),
	AR1 = 4     UMETA(DisplayName = "556x45"),
	AR2 = 5     UMETA(DisplayName = "762x39"),
	RIFLE1 = 6     UMETA(DisplayName = "762x54"),
	RIFLE2 = 7     UMETA(DisplayName = "308"),
	GRENADE1 = 8     UMETA(DisplayName = "Grenade"),
	GRENADE2 = 9     UMETA(DisplayName = "FireGrenade"),
	GRENADE3 = 10     UMETA(DisplayName = "RadGrenade"),
	ANOMALY = 11     UMETA(DisplayName = "Anomaly"),
	ARROW = 12     UMETA(DisplayName = "Arrow"),
	PLASMA = 13     UMETA(DisplayName = "Plasma"),
	LASER = 14     UMETA(DisplayName = "Laser"),
}; // not sure if we are even using this still but if so put in firearmbase too

USTRUCT(BlueprintType)
struct FS_MagazineBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;
};// consider moving to firearm base c++ class

USTRUCT(BlueprintType)
struct FS_AmmoBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		bool IsInBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		TEnumAsByte <E_AmmoTypes> AmmoType; //needs to derive from uint8 instead

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		float Penetration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		float FPS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoInfo")
		float Recoil;
};// consider moving to ammo base c++ class

USTRUCT(BlueprintType)
struct FS_FirearmBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		struct FS_MagazineBase MagazineType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunInfo")
		TArray< FS_AmmoBase > AmmoTypes;

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
		TArray< E_FireModes > FireMode;

};// consider moving to firearm base c++ class

USTRUCT(BlueprintType)
struct FS_SpawnPoint
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Name;
};// consider moving to spawnpoint base c++ class

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		class AItem_Base* ClassRef;

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
class WORKSNOW_API AItem_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
