// Created by dorgon, All Rights Reserved.
// Date of intended publication: 2019/08/01
// email: dorgonman@hotmail.com
// blog: dorgon.horizon-studio.net

#pragma once

// Core
#include "Misc/AssertionMacros.h"
#include "Algo/Accumulate.h"
#include "Misc/CommandLine.h"
#include "Logging/MessageLog.h"
//Engine
#include "Engine/Brush.h"
#include "Engine/Font.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/WorldSettings.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/CanvasPanelSlot.h"
#include "Fonts/FontMeasure.h"
#include "Materials/Material.h"


// UObject

#include "UObject/ConstructorHelpers.h"


// Sound
#include "Sound/SoundBase.h"

// Paper2D
#include "PaperSprite.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"

//SlateCore
#include "Fonts/SlateFontInfo.h"

//UMG
#include "UMGStyle.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/CheckBox.h"
#include "Components/Image.h"


// XmlParser
#include "XmlParser.h"


//General Log
//CORE_API DECLARE_LOG_CATEGORY_EXTERN(LogTemp, Log, All);
//HORIZONLIBRARY_API 
DECLARE_LOG_CATEGORY_EXTERN(LogHorizonUI, Log, All);
#define UE_HORIZONUI_FATAL(msg, ...)		UE_LOG(LogHorizonUI, Fatal, TEXT(msg), ##__VA_ARGS__)
#define UE_HORIZONUI_ERROR(msg, ...)		UE_LOG(LogHorizonUI, Error, TEXT(msg), ##__VA_ARGS__)
#define UE_HORIZONUI_WARNING(msg, ...)		UE_LOG(LogHorizonUI, Warning, TEXT(msg), ##__VA_ARGS__)
#define UE_HORIZONUI_DISPLAY(msg, ...)		UE_LOG(LogHorizonUI, Display, TEXT(msg), ##__VA_ARGS__)
#define UE_HORIZONUI_LOG(msg, ...)			UE_LOG(LogHorizonUI, Log, TEXT(msg), ##__VA_ARGS__)
#define UE_HORIZONUI_VERBOSE(msg, ...)		UE_LOG(LogHorizonUI, Verbose, TEXT(msg), ##__VA_ARGS__)
#define UE_HORIZONUI_VERY_VERBOSE(msg, ...) UE_LOG(LogHorizonUI, VeryVerbose, TEXT(msg), ##__VA_ARGS__)


