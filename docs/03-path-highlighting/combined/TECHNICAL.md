# Multiple Selection and Combined Paths — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Edge aggregation

The selection pass adds edges into `FGuidePaths::Selected`, deduplicating by `Edge.Child` within the aggregate. Hover edges are collected separately into `FGuidePaths::Hovered`.

## Per-segment maximum

`SGuideArrow::Collect` merges overlaps in a `TMap<int32,FRail>` where `Upper` and `Lower` retain the maximum contributing brightness. Horizontal connector brightness similarly uses a maximum. The result is independent of the number of selected children sharing a rail.

<figure class="doc-media" data-kind="image" data-media-id="combined-segment-aggregation"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Selection and hover contributions merge by maximum brightness for each connector segment."><figcaption>Selection and hover contributions merge by maximum brightness for each connector segment.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a labeled row/rail diagram with two selected child edges and one hovered edge. Show duplicated upper vertical segments merging into a single maximum brightness value.</span></figcaption></figure>

## Overlay correction

The renderer computes `(target-base)/(1-base)` for overlay alpha where base brightness is below 1. This compensates for baseline opacity so the effective guide does not become brighter than the configured target.

## Constraints

The intersection is handled per displayed row/guide depth. It does not create persistent hierarchy relationships or selection state separate from the native Outliner.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
