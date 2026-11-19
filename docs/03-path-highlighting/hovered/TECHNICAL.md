# Hovered Path Highlighting — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Hover detection

`FLabelColumn::UpdatePaths()` iterates installed native rows and checks `Row->IsHovered()`; it selects the first realized hovered row and reads its matching `ISceneOutlinerTreeItem`. That item's ancestor chain is converted into displayed `FGuideEdge` records.

## Limits of the event source

Only rows Stem has decorated are candidates for this hover lookup. The module intentionally does not treat pinned ancestor placeholder rows as normal hover targets, and does not implement a global mouse-position hierarchy lookup.

## Highlight combination

`SGuideArrow::Collect` uses `Settings->HoveredPathBrightness` only when `bHighlightHoveredPath` is on. The baseline and selected-path contributions are combined by maximum brightness, and the renderer avoids additive over-brightness.

<figure class="doc-media" data-kind="image" data-media-id="hovered-paint-merge"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Hovered and selected connector paths share a single bounded, non-additive render result."><figcaption>Hovered and selected connector paths share a single bounded, non-additive render result.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a conceptual guide-line diagram with a baseline segment, hovered segment, selected segment and overlap. Label base 0.15, hover 0.40 and selected 0.65 as default values, with overlap equal to max rather than a sum.</span></figcaption></figure>

## Performance

The active rows and displayed path data are sampled at most every 0.05 s for path updates; normal Slate rendering still repaints as needed. No Actors, asset packages or level data are modified.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
