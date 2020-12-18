// Created by horizon-studio, All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/TileView.h"
#include "HorizonTileView.generated.h"

/**
 * 
 */
UCLASS()
class HORIZONUI_API UHorizonTileView : public UTileView
{
	GENERATED_BODY()
public:
	UHorizonTileView(const FObjectInitializer& ObjectInitializer);
	bool IsFocusable();
#if WITH_EDITOR
	//~ Begin UObject Interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
	//~ End UObject Interface
#endif
#if WITH_EDITOR
private:
	void CalculateItemSize();
#endif
protected:

	//~ Begin UWidget Interface
	virtual void OnWidgetRebuilt() override;
	//~ End UWidget Interface


protected:
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;
protected:
#if WITH_EDITORONLY_DATA
	virtual void OnRefreshDesignerItems() override;
#endif



};
