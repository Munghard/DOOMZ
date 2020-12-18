// Created by horizon-studio, All Right Reserved


#include "Widget/Components/HorizonTileView.h"
#include "HorizonUIPrivate.h"

UHorizonTileView::UHorizonTileView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}




bool UHorizonTileView::IsFocusable()
{
	return bIsFocusable;
}

#if WITH_EDITOR
void UHorizonTileView::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	//if ((PropertyName == GET_MEMBER_NAME_CHECKED(UListViewBase, EntryWidgetClass)))
	if (PropertyName == TEXT("EntryWidgetClass"))
	{
		CalculateItemSize();
	}
}

void UHorizonTileView::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
	Super::PostEditChangeChainProperty(PropertyChangedEvent);

}

void UHorizonTileView::CalculateItemSize()
{
	auto entryWidgetClass = GetEntryWidgetClass();
	if (entryWidgetClass)
	{
		auto defaultItem = Cast<UUserWidget>(entryWidgetClass->GetDefaultObject());
		if (defaultItem)
		{
			SetEntryWidth(defaultItem->DesignTimeSize.X);
			SetEntryHeight(defaultItem->DesignTimeSize.Y);

		}
	}


}
#endif


void UHorizonTileView::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	RequestRefresh();
	ScrollToBottom();
}


UUserWidget& UHorizonTileView::OnGenerateEntryWidgetInternal(UObject* Item,
	TSubclassOf<UUserWidget> DesiredEntryClass,
	const TSharedRef<STableViewBase>& OwnerTable)
{
	auto& entryWidget = Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);

	return entryWidget;
}
#if WITH_EDITORONLY_DATA
void UHorizonTileView::OnRefreshDesignerItems()
{
	//RefreshDesignerItems<UObject*>(ListItems, [this]() {
	//	return nullptr;
	//});

}
#endif //#if WITH_EDITORONLY_DATA