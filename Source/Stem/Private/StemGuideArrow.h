#pragma once

#include "StemSettings.h"
#include "Widgets/Views/SExpanderArrow.h"
#include "Widgets/Views/ITableRow.h"
#include "Rendering/DrawElements.h"
#include "Styling/CoreStyle.h"

namespace Stem
{
struct FGuideEdge
{
    int32 Parent=0;
    int32 Child=0;
    int32 Depth=0;
};
struct FGuidePaths
{
    TArray<FGuideEdge> Selected;
    TArray<FGuideEdge> Hovered;
    bool bActive=true;
};

// Native expansion button and layout, with independently painted neutral guides.
class SGuideArrow final : public SExpanderArrow
{
public:
    SLATE_BEGIN_ARGS(SGuideArrow) {} SLATE_END_ARGS()
    void Construct(const FArguments&,const TSharedPtr<ITableRow>& Row,const TSharedRef<FGuidePaths>& InPaths)
    {
        Paths=InPaths;
        SExpanderArrow::Construct(SExpanderArrow::FArguments().IndentAmount(12.f).ShouldDrawWires(false),Row);
    }
protected:
    virtual int32 OnPaint(const FPaintArgs& Args,const FGeometry& Geometry,const FSlateRect& Culling,
        FSlateWindowElementList& Elements,int32 Layer,const FWidgetStyle& Style,bool bEnabled) const override
    {
        const auto Row=OwnerRowPtr.Pin();
        const UStemSettings* Settings=GetDefault<UStemSettings>();
        if(Row && Paths && Paths->bActive && Settings->bShowHierarchyGuides)
        {
            const float Thickness=FMath::Clamp(Settings->GuideThickness,1.f,4.f);
            const float Half=Geometry.GetLocalSize().Y*0.5f;
            const float Width=Geometry.GetLocalSize().X;
            const float Height=Geometry.GetLocalSize().Y;
            const float Base=FMath::Clamp(Settings->GuideBrightness,0.f,1.f);
            const auto& Wires=Row->GetWiresNeededByDepth();
            const int32 Levels=Wires.Num();
            const int32 Index=Row->GetIndexInList();
            const FSlateBrush* Brush=FCoreStyle::Get().GetBrush(TEXT("WhiteBrush"));
            // The triangle is painted above the guides, but its transparent
            // brush background still reveals lines underneath. Reserve the glyph
            // rectangle (plus a small gap) for both baseline and highlight passes.
            // Use current layout/brush dimensions, not last frame's cached geometry.
            const FSlateBrush* ArrowBrush=Row->DoesItemHaveChildren() ? GetExpanderImage() : nullptr;
            const bool bReserveArrow=ArrowBrush!=nullptr;
            const float ArrowCenterX=(GetExpanderPadding().Left+Width)*0.5f;
            const float ArrowHalfWidth=bReserveArrow ? ArrowBrush->ImageSize.X*0.5f+1.f : 0.f;
            const float ArrowHalfHeight=bReserveArrow ? ArrowBrush->ImageSize.Y*0.5f+1.f : 0.f;
            const float GapLeft=ArrowCenterX-ArrowHalfWidth;
            const float GapRight=ArrowCenterX+ArrowHalfWidth;
            const float GapTop=Half-ArrowHalfHeight;
            const float GapBottom=Half+ArrowHalfHeight;
            auto DrawBox=[&](float X,float Y,float W,float H,float Brightness,int32 DrawLayer) {
                if(W<=0.f || H<=0.f) return;
                const FLinearColor Tint(1.f,1.f,1.f,Brightness*Style.GetColorAndOpacityTint().A);
                FSlateDrawElement::MakeBox(Elements,DrawLayer,
                    Geometry.ToPaintGeometry(FVector2D(W,H),FSlateLayoutTransform(FVector2D(X,Y))),
                    Brush,bEnabled ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect,Tint);
            };
            auto Box=[&](float X,float Y,float W,float H,float Brightness,int32 DrawLayer) {
                if(W<=0.f || H<=0.f) return;
                const float Left=FMath::Max(X,GapLeft), Right=FMath::Min(X+W,GapRight);
                const float Top=FMath::Max(Y,GapTop), Bottom=FMath::Min(Y+H,GapBottom);
                if(!bReserveArrow || Left>=Right || Top>=Bottom)
                {
                    DrawBox(X,Y,W,H,Brightness,DrawLayer);
                    return;
                }
                // Four non-overlapping portions outside the triangle's bounds.
                DrawBox(X,Y,W,Top-Y,Brightness,DrawLayer);
                DrawBox(X,Bottom,W,Y+H-Bottom,Brightness,DrawLayer);
                DrawBox(X,Top,Left-X,Bottom-Top,Brightness,DrawLayer);
                DrawBox(Right,Top,X+W-Right,Bottom-Top,Brightness,DrawLayer);
            };
            auto Vertical=[&](int32 Depth,float Y0,float Y1,float Brightness,int32 DrawLayer) {
                // Center the stroke on the native two-unit rail, independent of thickness.
                Box(Depth*12.f-2.f-Thickness*0.5f,Y0,Thickness,Y1-Y0,Brightness,DrawLayer);
            };
            auto Horizontal=[&](int32 Depth,float Brightness,int32 DrawLayer) {
                const float Start=Depth*12.f-2.f;
                const float End=Width-3.f-(Row->DoesItemHaveChildren() ? 10.f : 0.f);
                Box(Start,Half-Thickness*0.5f,End-Start,Thickness,Brightness,DrawLayer);
            };
            for(int32 Depth=0;Depth<Levels;++Depth)
                if(Wires[Depth]) Vertical(Depth,0.f,Height,Base,Layer);
            if(Levels>0 && Row->IsLastChild()) Vertical(Levels-1,0.f,Half+Thickness*0.5f,Base,Layer);
            if(Row->IsItemExpanded() && Row->DoesItemHaveChildren())
                Vertical(Levels,Half-Thickness*0.5f,Height,Base,Layer);
            if(Levels>1) Horizontal(Levels-1,Base,Layer);

            // Merge overlapping highlighted segments before drawing. Shared paths
            // must not become brighter just because more descendants are selected.
            struct FRail { float Upper=0.f; float Lower=0.f; };
            TMap<int32,FRail> Rails;
            float HorizontalBrightness=0.f;
            auto Collect=[&](const TArray<FGuideEdge>& Edges,float Brightness) {
                Brightness=FMath::Max(Base,FMath::Clamp(Brightness,0.f,1.f));
                for(const FGuideEdge& Edge:Edges)
                {
                    if(Index<Edge.Parent || Index>Edge.Child) continue;
                    FRail& Rail=Rails.FindOrAdd(Edge.Depth);
                    if(Index>Edge.Parent) Rail.Upper=FMath::Max(Rail.Upper,Brightness);
                    if(Index<Edge.Child) Rail.Lower=FMath::Max(Rail.Lower,Brightness);
                    if(Index==Edge.Child && Levels>1)
                        HorizontalBrightness=FMath::Max(HorizontalBrightness,Brightness);
                }
            };
            if(Settings->bHighlightHoveredPath) Collect(Paths->Hovered,Settings->HoveredPathBrightness);
            if(Settings->bHighlightSelectedPaths) Collect(Paths->Selected,Settings->SelectedPathBrightness);
            // Highlight opacity is composited over the baseline; compensate so the
            // final brightness matches the configured value instead of adding to it.
            auto OverlayAlpha=[Base](float Value) { return Base<1.f ? FMath::Clamp((Value-Base)/(1.f-Base),0.f,1.f) : 0.f; };
            for(const auto& Pair:Rails)
            {
                if(Pair.Value.Upper>Base) Vertical(Pair.Key,0.f,Half,OverlayAlpha(Pair.Value.Upper),Layer+1);
                if(Pair.Value.Lower>Base) Vertical(Pair.Key,Half,Height,OverlayAlpha(Pair.Value.Lower),Layer+1);
            }
            if(HorizontalBrightness>Base) Horizontal(Levels-1,OverlayAlpha(HorizontalBrightness),Layer+1);
        }
        return SExpanderArrow::OnPaint(Args,Geometry,Culling,Elements,Layer+2,Style,bEnabled);
    }
private:
    TSharedPtr<FGuidePaths> Paths;
};
}
