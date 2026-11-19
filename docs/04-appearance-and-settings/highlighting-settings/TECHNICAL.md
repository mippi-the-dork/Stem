# Highlight Preferences — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Settings and edit conditions

`UStemSettings` declares two enable flags and their brightness properties. The brightness fields have `EditCondition` metadata depending on their respective enable flags. All brightness fields are clamped to 0–1.

## Calculation and paint

The sampled paths are stored in `FGuidePaths::Selected` and `Hovered`. `SGuideArrow::Collect` receives each group with its respective brightness and merges by maximum. It enforces a lower bound of neutral Guide Brightness for visible highlighted segments.

<figure class="doc-media" data-kind="image" data-media-id="highlight-palette-merge"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Hovered and selected highlights combine without additive over-brightness."><figcaption>Hovered and selected highlights combine without additive over-brightness.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a horizontal connector comparison showing baseline at 0.15, hover at 0.40, selected at 0.65, and the combined segment at the stronger of the two.</span></figcaption></figure>

## No new event ownership

Settings do not replace native selection logic. Selected rows come from the Outliner tree; hover is read from installed realized rows. Disabling a highlight only removes its painted contribution.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
