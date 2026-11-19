# First Use — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## What happens when an Outliner row is created

`FLabelColumn::ConstructRowWidget` forwards to the original label-column factory without altering the returned label widget. It queues compatible `SSceneOutlinerTreeRow` instances for later examination because the expansion widget is inserted after label construction completes.

## Deferred expander installation

On subsequent column ticks, `FindArrow` searches newly generated row widgets (bounded depth), locates the native `SExpanderArrow` in the appropriate horizontal box, measures the replacement using `SlatePrepass`, and substitutes `SGuideArrow` into slot zero. It avoids walking the entire UI widget tree every frame.

<figure class="doc-media" data-kind="image" data-media-id="first-use-render-pipeline">
  <img src="../../assets/media-placeholder.png" alt="Stem wraps the existing label and replaces the native expander only after the row is fully constructed." loading="lazy">
  <figcaption>Stem wraps the existing label and replaces the native expander only after the row is fully constructed.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Draw a sequence: native Outliner creates row → original label widget returned → row queued → native expander found on later tick → SGuideArrow prepassed and inserted → guides painted. Include the original arrow retained for cleanup.</span></figcaption>
</figure>

## State and timing

A per-Outliner `FGuidePaths` stores selected and hovered connector edges. `FLabelColumn::Tick` updates path calculations at most every **0.05 seconds**, then invalidates installed guide arrows for repaint. Hover is read from realized Outliner rows, not from a new global selection system.

## No user-data mutations

The exercise only updates native Outliner rendering and configured `UStemSettings`. It does not call Actor `Modify()`, change parent references or dirty map packages.

---

**Verification:** Stem code and the repository's manual-test claims were reviewed; no new hands-on Unreal test has been executed for this documentation pass.

[Design guide](DESIGN.md) · [Implementation references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
