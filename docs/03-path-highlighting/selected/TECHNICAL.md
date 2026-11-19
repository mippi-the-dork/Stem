# Selected Path Highlighting — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Path source

`FLabelColumn::UpdatePaths()` reads `View->GetTree().GetSelectedItems()`. It traverses each item's `ISceneOutlinerTreeItem::GetParent()` chain and builds `FGuideEdge` records for displayed ancestors and descendants.

<figure class="doc-media" data-kind="image" data-media-id="selected-path-flow"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Selected path edges are derived from the displayed tree and combined by guide segment."><figcaption>Selected path edges are derived from the displayed tree and combined by guide segment.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a small flowchart with native selected Outliner rows, displayed row indices, ancestor traversals, FGuidePaths::Selected and SGuideArrow paint passes.</span></figcaption></figure>

## Timing and recomputation

`FLabelColumn::Tick` calls `UpdatePaths` no more often than once per **0.05 seconds** and invalidates installed arrows for paint. Path computation reads UI tree items; it does not enumerate all Actors in the world.

## Color/brightness

`SGuideArrow::Collect` clamps selected brightness to **0–1** and ensures it is no lower than base Guide Brightness. Guide segments are combined with max brightness. The computed overlay opacity is compensated for the already-painted baseline.

## Disabling

`bHighlightSelectedPaths` prevents selected edges from contributing to the highlight, while neutral guides may remain enabled. When guides are disabled globally, `UpdatePaths` exits early and `SGuideArrow` skips painting.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
