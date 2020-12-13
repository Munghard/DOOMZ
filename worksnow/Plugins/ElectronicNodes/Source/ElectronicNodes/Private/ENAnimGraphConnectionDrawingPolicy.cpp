/* Copyright (C) 2019 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "ENAnimGraphConnectionDrawingPolicy.h"
#include "ENConnectionDrawingPolicy.h"

void FENAnimGraphConnectionDrawingPolicy::DrawConnection(int32 LayerId, const FVector2D& Start, const FVector2D& End, const FConnectionParams& Params)
{
	this->connectionDrawingPolicy->SetMousePosition(LocalMousePosition);
	this->connectionDrawingPolicy->DrawConnection(LayerId, Start, End, Params);
	SplineOverlapResult = FGraphSplineOverlapResult(this->connectionDrawingPolicy->SplineOverlapResult);
}
