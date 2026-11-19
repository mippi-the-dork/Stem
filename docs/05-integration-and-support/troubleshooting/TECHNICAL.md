# Troubleshooting and FAQ — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Symptom-to-source map

| Symptom | Inspect |
| --- | --- |
| No column integration | `FStemModule::StartupModule`, `OnCreateActorBrowserColumns` |
| Missing guides on native row | `FLabelColumn::Tick`, `FindArrow`, `SGuideArrow::OnPaint` |
| No selected or hovered highlights | `UpdatePaths` selection/hover edge creation |
| Unexpected path brightness | `SGuideArrow::Collect`, max-merge and overlay alpha |
| Spacing unchanged | `FRowHeightColumn::ConstructRowWidget`, native minimum, settings refresh |
| Crash or stale widgets after unload | `FLabelColumn::Stop`, weak pointers, registry lifetime |

## Reproduction matrix

Use a fresh UE 5.8 project with normal World Outliner rows and nested Actors/Folders. Check defaults first. Add a custom Outliner/plugin decorator only after native behavior is confirmed. Test expanded/collapsed branches, filtered rows, multi-select, hover, settings changes, tab close/reopen and editor restart.

## Observability boundary

Stem's public source is compact but contains no documented comprehensive native Automation suite. Repository manual tests in UE 5.8.2 are a historical claim; a troubleshooting guide should not present new tests as passed without logs or reproduction evidence.

<figure class="doc-media" data-kind="image" data-media-id="troubleshoot-state-sequence"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Isolating a Stem display issue starts with plugin activation, visible native rows, settings and eligible expanders."><figcaption>Isolating a Stem display issue starts with plugin activation, visible native rows, settings and eligible expanders.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a diagnostic decision tree: plugin enabled? standard Outliner? expanded rows? guides enabled? compatible SExpanderArrow? selected/hover path settings? Point each branch to its resolution.</span></figcaption></figure>

---

**Validation:** Source inspected; new in-editor testing has not been performed for this documentation pass.

[Design guide](DESIGN.md) · [Source references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
