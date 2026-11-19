# Guide Visibility, Brightness and Thickness — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Settings fields

`UStemSettings` declares `bShowHierarchyGuides`, `GuideBrightness` (Clamp 0–1), and `GuideThickness` (Clamp 1–4) with `UPROPERTY(Config,EditAnywhere)`. Values reside in the Stem configuration section.

## OnPaint behavior

`SGuideArrow::OnPaint` checks `bShowHierarchyGuides` and `FGuidePaths::bActive`. It clamps thickness to 1–4 and brightness to 0–1, then constructs neutral guide boxes tinted through `FLinearColor(1,1,1,alpha)`.

## Arrow collision avoidance

The same rectangle-clipping function excludes the expansion triangle and one-unit margin from baseline and highlighted strokes, based on current geometry and arrow brush dimensions.

<figure class="doc-media" data-kind="image" data-media-id="guide-paint-geometry"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Guide strokes are clipped around the native expansion triangle before it is painted."><figcaption>Guide strokes are clipped around the native expansion triangle before it is painted.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a close-up diagram of SGuideArrow with vertical/horizontal strokes, the triangle brush bounds, gap rectangle and normal/highlight paint layers.</span></figcaption></figure>

## State ownership

Settings affect Slate appearance and do not call native Actor setters. No Actor package data or runtime state is persisted as a result.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
