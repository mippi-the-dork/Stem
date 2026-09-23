// Copyright Epic Games, Inc. All Rights Reserved.

#include "StemSettings.h"
#include "StemOutlinerRefresh.h"
#include "UObject/UnrealType.h"

#if WITH_EDITOR
void UStemSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    const FName PropertyName = PropertyChangedEvent.Property
        ? PropertyChangedEvent.Property->GetFName()
        : NAME_None;

    if (PropertyName == GET_MEMBER_NAME_CHECKED(UStemSettings, RowHeight))
    {
        Stem::RefreshOutlinersForRowHeight();
    }
}
#endif
