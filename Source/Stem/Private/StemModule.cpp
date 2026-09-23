// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"
#include "StemSettings.h"
#include "StemGuideArrow.h"
#include "StemOutlinerRefresh.h"
#include "ISceneOutlinerTreeItem.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Views/STreeView.h"
#include "ISceneOutliner.h"
#include "ISceneOutlinerColumn.h"
#include "SceneOutlinerModule.h"
#include "SceneOutlinerPublicTypes.h"
#include "Layout/Children.h"
#include "Widgets/Views/SExpanderArrow.h"
#include "Widgets/Views/SHeaderRow.h"
#include "Widgets/Views/STableRow.h"

namespace Stem
{
using FRow=STableRow<FSceneOutlinerTreeItemPtr>;

// A visually hidden auxiliary column that contributes only vertical desired size.
// Keeping this separate from Item Label preserves the native label widget type for
// Chroma and leaves Unreal's icons, expander arrows, selection, and row behavior intact.
class FRowHeightColumn final : public ISceneOutlinerColumn
{
public:
    static FName GetID()
    {
        static const FName ColumnID(TEXT("StemRowHeightColumn"));
        return ColumnID;
    }

    virtual FName GetColumnID() override { return GetID(); }

    virtual SHeaderRow::FColumn::FArguments ConstructHeaderRowColumn() override
    {
        return SHeaderRow::Column(GetID())
            .DefaultLabel(FText::GetEmpty())
            .DefaultTooltip(NSLOCTEXT("Stem", "StemRowHeightColumnTooltip", "Stem World Outliner row spacing"))
            .ManualWidth(1.0f)
            .Visibility(EVisibility::Hidden);
    }

    virtual const TSharedRef<SWidget> ConstructRowWidget(FSceneOutlinerTreeItemRef,const FRow&) override
    {
        const float NativeRowHeight=static_cast<float>(FSceneOutlinerDefaultTreeItemMetrics::RowHeight());
        const float DesiredRowHeight=FMath::Max(NativeRowHeight,GetDefault<UStemSettings>()->RowHeight);
        return SNew(SBox).MinDesiredHeight(DesiredRowHeight);
    }
};

// Return the original label widget unchanged. In particular, Chroma must still
// see the native label type, regardless of which column decorator runs first.
class FLabelColumn final : public ISceneOutlinerColumn
{
    struct FPending
    {
        TWeakPtr<FRow> Row;
        TWeakPtr<ISceneOutlinerTreeItem> Item;
        int32 Attempts=0;
    };
    struct FInstalled
    {
        TWeakPtr<FRow> Row;
        TWeakPtr<SGuideArrow> Arrow;
        TWeakPtr<SHorizontalBox> Box;
        TWeakPtr<ISceneOutlinerTreeItem> Item;
        TSharedPtr<SExpanderArrow> OriginalArrow;
    };
    TSharedRef<ISceneOutlinerColumn> Original;
    TArray<FPending> Pending;
    TArray<FInstalled> Installed;
    bool bStopped=false;
    TWeakPtr<ISceneOutliner> Outliner;
    TSharedRef<FGuidePaths> Paths=MakeShared<FGuidePaths>();
    double NextPathUpdate=0.0;

    static TSharedPtr<SExpanderArrow> FindArrow(const TSharedRef<SWidget>& Widget,TSharedPtr<SHorizontalBox>& Parent,int32 Depth=0)
    {
        if(Depth>12) return nullptr;
        if(FChildren* Children=Widget->GetChildren())
            for(int32 I=0;I<Children->Num();++I)
                {
                const auto Child=Children->GetChildAt(I);
                if(Widget->GetType()==FName(TEXT("SHorizontalBox")) && I==0 && Child->GetType()==FName(TEXT("SExpanderArrow")))
                {
                    Parent=StaticCastSharedRef<SHorizontalBox>(Widget);
                    return StaticCastSharedRef<SExpanderArrow>(Child);
                }
                if(auto Arrow=FindArrow(Child,Parent,Depth+1)) return Arrow;
            }
        return nullptr;
    }

public:
    explicit FLabelColumn(TSharedRef<ISceneOutlinerColumn> InOriginal,ISceneOutliner& View) : Original(InOriginal), Outliner(StaticCastSharedRef<ISceneOutliner>(View.AsShared())) {}

    virtual FName GetColumnID() override { return Original->GetColumnID(); }
    virtual SHeaderRow::FColumn::FArguments ConstructHeaderRowColumn() override { return Original->ConstructHeaderRowColumn(); }
    virtual const TSharedRef<SWidget> ConstructRowWidget(FSceneOutlinerTreeItemRef Item,const FRow& Row) override
    {
        const TSharedRef<SWidget> Widget=Original->ConstructRowWidget(Item,Row);
        // Pinned rows intentionally have hidden indentation placeholders, not a
        // normal tree expander. Third-party row layouts are outside this prototype.
        if(!bStopped && Row.GetType()==FName(TEXT("SSceneOutlinerTreeRow")))
        {
            FPending Entry;
            Entry.Row=ConstCastSharedRef<FRow>(StaticCastSharedRef<const FRow>(Row.AsShared()));
            Entry.Item=Item;
            Pending.Add(MoveTemp(Entry));
        }
        return Widget;
    }

    virtual void Tick(double Now,float Delta) override
    {
        Original->Tick(Now,Delta);
        if(bStopped) return;
        Installed.RemoveAll([](const FInstalled& Entry) { return !Entry.Row.IsValid() || !Entry.Arrow.IsValid(); });
        // The Outliner creates its expander AFTER ConstructRowWidget returns.
        // Inspect only newly generated rows on a later column tick, never actors
        // or the entire widget tree on every frame.
        for(int32 I=Pending.Num()-1;I>=0;--I)
        {
            const TSharedPtr<FRow> Row=Pending[I].Row.Pin();
            if(!Row) { Pending.RemoveAtSwap(I); continue; }
            TSharedPtr<SHorizontalBox> Box;
            const auto Arrow=FindArrow(Row.ToSharedRef(),Box);
            if(!Arrow)
            {
                if(++Pending[I].Attempts>=3) Pending.RemoveAtSwap(I);
                continue;
            }
            if(Box && Arrow->GetVisibility()==EVisibility::Visible)
            {
                // Replace only slot zero of the exact native indentation box.
                // The label slot, row, selection, and drag/drop handlers stay intact.
                if(Box->GetChildren()->Num()>0 && Box->GetChildren()->GetChildAt(0)==Arrow.ToSharedRef())
                {
                    const auto Guide=SNew(SGuideArrow,StaticCastSharedRef<ITableRow>(Row.ToSharedRef()),Paths);
                    // This runs after the normal layout prepass on some frames.
                    // Prime the new expander's indentation/button width BEFORE
                    // inserting it; an unmeasured AutoWidth child has zero width
                    // and briefly pulls the actor icon and label to the left.
                    const float LayoutScale=Row->GetCachedGeometry().GetAccumulatedLayoutTransform().GetScale();
                    Guide->SlatePrepass(LayoutScale);
                    Box->RemoveSlot(Arrow.ToSharedRef());
                    Box->InsertSlot(0).AutoWidth().Padding(6.f,0.f,0.f,0.f)[Guide];
                    Box->Invalidate(EInvalidateWidgetReason::Layout);
                    Box->SlatePrepass(LayoutScale);
                    FInstalled Entry; Entry.Row=Row; Entry.Arrow=Guide; Entry.Box=Box;
                    Entry.Item=Pending[I].Item; Entry.OriginalArrow=Arrow;
                    Installed.Add(MoveTemp(Entry));
                }
            }
            Pending.RemoveAtSwap(I);
        }
        if(Now>=NextPathUpdate)
        {
            NextPathUpdate=Now+0.05;
            UpdatePaths();
            for(const auto& Entry:Installed) if(auto Arrow=Entry.Arrow.Pin()) Arrow->Invalidate(EInvalidateWidgetReason::Paint);
        }
    }

    void UpdatePaths()
    {
        Paths->Selected.Reset(); Paths->Hovered.Reset();
        const auto View=Outliner.Pin();
        const UStemSettings* Settings=GetDefault<UStemSettings>();
        if(!View || !Settings->bShowHierarchyGuides) return;
        FSceneOutlinerTreeItemPtr Hovered;
        if(Settings->bHighlightHoveredPath)
            for(const auto& Entry:Installed)
                if(auto Row=Entry.Row.Pin()) if(Row->IsHovered()) { Hovered=Entry.Item.Pin(); break; }
        const auto Selected=View->GetTree().GetSelectedItems();
        if(!Hovered && (!Settings->bHighlightSelectedPaths || Selected.IsEmpty())) return;
        // The SListView base exposes the displayed, expanded tree sequence. Do not
        // use STreeView's root items: those omit the intermediate connector rows.
        const auto Items=static_cast<const SListView<FSceneOutlinerTreeItemPtr>&>(View->GetTree()).GetItems();
        TMap<const ISceneOutlinerTreeItem*,int32> Indices;
        TArray<int32> Depths; Depths.SetNumZeroed(Items.Num());
        for(int32 I=0;I<Items.Num();++I)
        {
            if(!Items[I]) continue;
            if(auto Parent=Items[I]->GetParent()) if(const int32* ParentIndex=Indices.Find(Parent.Get()))
                Depths[I]=Depths[*ParentIndex]+1;
            Indices.Add(Items[I].Get(),I);
        }
        auto AddPath=[&](FSceneOutlinerTreeItemPtr Item,TArray<FGuideEdge>& Edges) {
            TSet<const ISceneOutlinerTreeItem*> Visited;
            while(Item && !Visited.Contains(Item.Get()))
            {
                Visited.Add(Item.Get());
                const auto Parent=Item->GetParent();
                if(!Parent) break;
                const int32* ChildIndex=Indices.Find(Item.Get());
                const int32* ParentIndex=Indices.Find(Parent.Get());
                if(ChildIndex && ParentIndex && *ParentIndex<*ChildIndex)
                {
                    bool Exists=false;
                    for(const auto& Edge:Edges) if(Edge.Child==*ChildIndex) { Exists=true; break; }
                    if(!Exists)
                    {
                        FGuideEdge Edge; Edge.Parent=*ParentIndex; Edge.Child=*ChildIndex; Edge.Depth=Depths[*ChildIndex];
                        Edges.Add(Edge);
                    }
                }
                Item=Parent;
            }
        };
        if(Settings->bHighlightSelectedPaths) for(const auto& Item:Selected) AddPath(Item,Paths->Selected);
        if(Hovered) AddPath(Hovered,Paths->Hovered);
    }

    void Stop()
    {
        bStopped=true; Paths->bActive=false;
        for(const FInstalled& Entry:Installed)
        {
            const auto Box=Entry.Box.Pin(); const auto Arrow=Entry.Arrow.Pin();
            if(Box && Arrow && Entry.OriginalArrow && Box->GetChildren()->Num()>0 && Box->GetChildren()->GetChildAt(0)==Arrow.ToSharedRef())
            {
                Box->RemoveSlot(Arrow.ToSharedRef());
                Box->InsertSlot(0).AutoWidth().Padding(6.f,0.f,0.f,0.f)[Entry.OriginalArrow.ToSharedRef()];
            }
        }
        Pending.Reset(); Installed.Reset();
    }
    virtual void PopulateSearchStrings(const ISceneOutlinerTreeItem& Item,TArray<FString>& Strings) const override { Original->PopulateSearchStrings(Item,Strings); }
    virtual bool SupportsSorting() const override { return Original->SupportsSorting(); }
    virtual void SortItems(TArray<FSceneOutlinerTreeItemPtr>& Items,EColumnSortMode::Type Mode) const override { Original->SortItems(Items,Mode); }
    virtual void OnSortRequested(EColumnSortPriority::Type Priority,EColumnSortMode::Type Mode) override { Original->OnSortRequested(Priority,Mode); }
    virtual bool IsSortReady() override { return Original->IsSortReady(); }
};

struct FRegistry
{
    bool bActive=true;
    TArray<TWeakPtr<FLabelColumn>> Columns;
    TArray<TWeakPtr<ISceneOutliner>> Outliners;

    void RegisterOutliner(ISceneOutliner& View)
    {
        Outliners.RemoveAll([](const TWeakPtr<ISceneOutliner>& Entry) { return !Entry.IsValid(); });
        Outliners.AddUnique(StaticCastSharedRef<ISceneOutliner>(View.AsShared()));
    }

    void FullRefreshOutliners()
    {
        Outliners.RemoveAll([](const TWeakPtr<ISceneOutliner>& Entry) { return !Entry.IsValid(); });
        for(const auto& Weak:Outliners)
            if(const auto View=Weak.Pin()) View->FullRefresh();
    }
};

static TWeakPtr<FRegistry> GRegistry;

void RefreshOutlinersForRowHeight()
{
    if(const TSharedPtr<FRegistry> Registry=GRegistry.Pin())
    {
        Registry->FullRefreshOutliners();
    }
}
}

class FStemModule final : public IModuleInterface
{
    FDelegateHandle ColumnHandle;
    TSharedPtr<Stem::FRegistry> Registry;
public:
    virtual void StartupModule() override
    {
        if(IsRunningCommandlet()) return;
        Registry=MakeShared<Stem::FRegistry>();
        Stem::GRegistry=Registry;
        const auto State=Registry.ToSharedRef();
        auto& Module=FModuleManager::LoadModuleChecked<FSceneOutlinerModule>(TEXT("SceneOutliner"));
        ColumnHandle=Module.OnCreateActorBrowserColumns().AddLambda([State](FSceneOutlinerInitializationOptions& Options,UWorld*) {
            // Stem owns general Outliner readability. This hidden column contributes
            // row height only; it does not expose UI or alter the label column.
            Options.ColumnMap.Add(
                Stem::FRowHeightColumn::GetID(),
                FSceneOutlinerColumnInfo(
                    ESceneOutlinerColumnVisibility::Visible,
                    251,
                    FCreateSceneOutlinerColumn::CreateLambda([State](ISceneOutliner& View) -> TSharedRef<ISceneOutlinerColumn> {
                        State->RegisterOutliner(View);
                        return MakeShared<Stem::FRowHeightColumn>();
                    }),
                    false,
                    TOptional<float>(),
                    NSLOCTEXT("Stem", "StemRowHeightColumnLabel", "Stem Row Height")));

            auto* Label=Options.ColumnMap.Find(FSceneOutlinerBuiltInColumnTypes::Label());
            if(!Label || !State->bActive) return;
            const FCreateSceneOutlinerColumn Previous=Label->Factory;
            Label->Factory=FCreateSceneOutlinerColumn::CreateLambda([Previous,State](ISceneOutliner& View) -> TSharedRef<ISceneOutlinerColumn> {
                State->RegisterOutliner(View);
                const TSharedPtr<ISceneOutlinerColumn> Original=Previous.IsBound() ?
                    TSharedPtr<ISceneOutlinerColumn>(Previous.Execute(View)) :
                    FModuleManager::LoadModuleChecked<FSceneOutlinerModule>(TEXT("SceneOutliner")).FactoryColumn(FSceneOutlinerBuiltInColumnTypes::Label(),View);
                check(Original.IsValid());
                if(!State->bActive) return Original.ToSharedRef();
                State->Columns.RemoveAll([](const TWeakPtr<Stem::FLabelColumn>& Entry) { return !Entry.IsValid(); });
                const auto Column=MakeShared<Stem::FLabelColumn>(Original.ToSharedRef(),View);
                State->Columns.Add(Column);
                return Column;
            });
        });

    }
    virtual void ShutdownModule() override
    {
        if(auto* Module=FModuleManager::GetModulePtr<FSceneOutlinerModule>(TEXT("SceneOutliner")))
            Module->OnCreateActorBrowserColumns().Remove(ColumnHandle);
        if(Registry)
        {
            Registry->bActive=false;
            for(const auto& Weak:Registry->Columns) if(auto Column=Weak.Pin()) Column->Stop();
            Registry->Columns.Reset(); Registry->Outliners.Reset(); Registry.Reset();
        }
        Stem::GRegistry.Reset();
    }
    virtual bool SupportsDynamicReloading() override { return false; }
};
IMPLEMENT_MODULE(FStemModule,Stem)
