// Created by horizon-studio, All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Widget/Components/HorizonDialogueMsgTextBlock.h"
#include "HorizonDialogueMsgDecorator.generated.h"


/**
 * 
 */
UCLASS(abstract, Blueprintable)
class HORIZONUI_API UHorizonDialogueMsgDecorator : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category = "HorizonPlugin|UI|DialogueMsgDecorator")
	bool PreRun(UHorizonDialogueMsgTextBlock* InMsgTextBlock,
			UPARAM(ref) FHorizonDialogueBlockInfo& InDialogueBlockInfo,
			UPARAM(ref) FHorizonDialogueSegmentInfo& InSegInfo);
	virtual bool PreRun_Implementation(UHorizonDialogueMsgTextBlock* InMsgTextBlock,
		FHorizonDialogueBlockInfo& InDialogueBlockInfo,
		FHorizonDialogueSegmentInfo& InSegInfo) {return false;};


	UFUNCTION(BlueprintNativeEvent, Category = "HorizonPlugin|UI|DialogueMsgDecorator")
	bool Run(UHorizonDialogueMsgTextBlock* InMsgTextBlock,
			UPARAM(ref) FHorizonDialogueBlockInfo& InDialogueBlockInfo, 
			UPARAM(ref) FHorizonDialogueSegmentInfo& InSegInfo);
	virtual bool Run_Implementation(UHorizonDialogueMsgTextBlock* InMsgTextBlock,
									FHorizonDialogueBlockInfo& InDialogueBlockInfo,
									FHorizonDialogueSegmentInfo& InSegInfo){return false;};
};
