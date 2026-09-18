// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "StemSettings.generated.h"

UCLASS(Config=Stem, DefaultConfig, meta=(DisplayName="Stem"))
class STEM_API UStemSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, Category="Outliner", meta=(DisplayName="Show Hierarchy Guides", ToolTip="Draw connector lines beside the World Outliner's expansion arrows to clarify folder and actor relationships."))
    bool bShowHierarchyGuides=true;

    UPROPERTY(Config, EditAnywhere, Category="Appearance", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0", ToolTip="Brightness of the neutral gray guides, from invisible to white."))
    float GuideBrightness=0.15f;

    UPROPERTY(Config, EditAnywhere, Category="Appearance", meta=(ClampMin="1.0", ClampMax="4.0", UIMin="1.0", UIMax="4.0", ToolTip="Guide stroke width in Slate units. Scales with the editor UI."))
    float GuideThickness=2.0f;

    UPROPERTY(Config, EditAnywhere, Category="Highlighting", meta=(DisplayName="Highlight Selected Paths", ToolTip="Brighten the connector paths from selected rows to their visible ancestors. Multiple selections combine their paths."))
    bool bHighlightSelectedPaths=true;

    UPROPERTY(Config, EditAnywhere, Category="Highlighting", meta=(EditCondition="bHighlightSelectedPaths", ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
    float SelectedPathBrightness=0.65f;

    UPROPERTY(Config, EditAnywhere, Category="Highlighting", meta=(DisplayName="Highlight Hovered Path", ToolTip="Temporarily brighten the ancestor path of the row under the cursor without changing selection."))
    bool bHighlightHoveredPath=true;

    UPROPERTY(Config, EditAnywhere, Category="Highlighting", meta=(EditCondition="bHighlightHoveredPath", ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
    float HoveredPathBrightness=0.40f;

    virtual FName GetSectionName() const override { return TEXT("Stem"); }
    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
};
