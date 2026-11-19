# Editor Architecture — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## An editor presentation tool

Stem augments the standard World Outliner, not the underlying world hierarchy. It doesn't add a separate window, visible column, special Actor, or runtime module.

## What happens when a row appears?

The existing label widget is created normally. Stem installs an `SGuideArrow` at the native expander location once the row is constructed, retaining the original expansion control for restoration. Its hidden layout-only column independently contributes row height.

<figure class="doc-media" data-kind="image" data-media-id="editor-architecture"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Stem preserves native World Outliner labels while adding guide rendering and optional vertical spacing."><figcaption>Stem preserves native World Outliner labels while adding guide rendering and optional vertical spacing.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Make an architecture diagram with FStemModule, Actor Browser registration, FLabelColumn wrapping the label factory, SGuideArrow rendering, hidden FRowHeightColumn, UStemSettings, and FGuidePaths.</span></figcaption></figure>

## How highlights are found

Stem reads displayed tree rows and their ancestor relationships, using native selected items and realized hovered rows. It never needs to enumerate every Actor in the level to calculate highlights.

## Why no visible column?

A tiny hidden column contributes desired row height. The Item Label column remains the original label's type/content, avoiding unnecessary interference with Unreal's icons, sorting, selection and other decorators.

## Boundaries

Custom Scene Outliner implementations and specialized expander widget hierarchies are not guaranteed to receive guides. Stem is not an alternative Outliner or a runtime navigation structure.

---

[Technical details](TECHNICAL.md) · [Integration and Support overview](../README.md)
