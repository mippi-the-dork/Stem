# What Stem Does — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Module boundary

`Stem.uplugin` defines one module (`Stem`), type `Editor`, loaded `PostEngineInit`, with a `Win64` allowlist and no content module. `Source/Stem/Stem.Build.cs` depends on `SceneOutliner`, `Slate`, `SlateCore`, and the settings infrastructure.

## Implementation responsibilities

The [module source](https://github.com/mippi-the-dork/Stem/blob/main/Source/Stem/Private/StemModule.cpp) decorates the existing World Outliner label column and registers an additional **layout-only hidden column** to contribute row height. [SGuideArrow](https://github.com/mippi-the-dork/Stem/blob/main/Source/Stem/Private/StemGuideArrow.h) preserves native expansion behavior while painting hierarchy guides and highlights.

<figure class="doc-media" data-kind="image" data-media-id="architecture-at-a-glance">
  <img src="../../assets/media-placeholder.png" alt="Stem's editor module coordinates native Outliner label decoration, path sampling, guide rendering, and row-height layout." loading="lazy">
  <figcaption>Stem's editor module coordinates native Outliner label decoration, path sampling, guide rendering, and row-height layout.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a diagram with the Scene Outliner module, FLabelColumn, SGuideArrow, FGuidePaths, hidden FRowHeightColumn, and UStemSettings. Distinguish painting from layout and show no modification to Actor data.</span></figcaption>
</figure>

## Data ownership

There is no Stem Actor, Component, data asset or level metadata. Preferences are `UStemSettings` (`Config=Stem, DefaultConfig`); row and path data are temporary Slate/editor structures.

## Scope boundary

The decorator is registered through `FSceneOutlinerModule::OnCreateActorBrowserColumns`. It operates on compatible native rows and expanders in the standard Actor Browser. A nonstandard Outliner picker or custom row widget may not be recognized. This is a limitation, not a fallback to rewriting the hierarchy.

---

**Verification:** Stem code and the repository's manual-test claims were reviewed; no new hands-on Unreal test has been executed for this documentation pass.

[Design guide](DESIGN.md) · [Implementation references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
