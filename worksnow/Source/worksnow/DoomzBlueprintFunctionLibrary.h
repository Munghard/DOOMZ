// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DoomzBlueprintFunctionLibrary.generated.h"


UCLASS()

class WORKSNOW_API UDoomzBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "TestCategory")
		static void MyMagicFunction(FString SomeString);

		/** returns a list of all save games in /Saved/SaveGames folder, without the .sav extension (filename only) */
		UFUNCTION(BlueprintPure, Category = "TestCategory")
		static TArray<FString> GetAllSaveGameSlotNames();

};
