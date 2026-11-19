# Hierarchy Guide Lines — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Guide geometry

`SGuideArrow` subclasses `SExpanderArrow` and retains `SExpanderArrow::Construct` with **12-unit indentation** and `ShouldDrawWires(false)`. It draws its own neutral guides using `FSlateDrawElement::MakeBox`.

<figure class="doc-media" data-kind="image" data-media-id="guides-geometry">
  <img src="../../assets/media-placeholder.png" alt="Stem uses Unreal's displayed row depth and native wire flags to draw branch segments beside expansion arrows." loading="lazy">
  <figcaption>Stem uses Unreal's displayed row depth and native wire flags to draw branch segments beside expansion arrows.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Diagram nested rows with 12-unit indentation, vertical rails, horizontal connectors, and a gap surrounding the expansion triangle. Label the geometry from ITableRow::GetWiresNeededByDepth and GetIndexInList.</span></figcaption>
</figure>

## Native row cues

`ITableRow::GetWiresNeededByDepth()`, `IsLastChild()`, `IsItemExpanded()` and `DoesItemHaveChildren()` determine the baseline vertical/horizontal strokes. Thickness is clamped to **1–4 Slate units**; brightness to **0–1**.

## Glyph clearance

The code queries the current arrow brush dimensions and reserves a gap around its bounding rectangle. Both neutral and highlighted line passes avoid painting across the triangle. The actual arrow is then painted above the guides through the superclass `OnPaint`.

## No scene mutation

The guides use the UI tree's displayed depth and relationships, not changes to Actor or Folder structures. Their paint calculations live in Slate and are not saved into map data.

---

**Verification:** Stem code and the repository's manual-test claims were reviewed; no new hands-on Unreal test has been executed for this documentation pass.

[Design guide](DESIGN.md) · [Implementation references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
