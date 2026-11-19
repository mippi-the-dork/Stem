# Displayed Hierarchies and Limits — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Display order and ancestry

`FLabelColumn::UpdatePaths` accesses the Outliner tree through its public `SListView` base and calls `GetItems()` to read the displayed, expanded sequence. For each item, it resolves `GetParent()`, recording indices and nesting depth.

<figure class="doc-media" data-kind="image" data-media-id="visible-tree-indices">
  <img src="../../assets/media-placeholder.png" alt="Stem builds ancestor paths from the displayed tree order, not from a global list of world Actors." loading="lazy">
  <figcaption>Stem builds ancestor paths from the displayed tree order, not from a global list of world Actors.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Diagram displayed row indices and depths for an expanded Outliner and show a collapsed child absent from the list. Mark parent indices, child indices, and generated path edges.</span></figcaption>
</figure>

## Selected/hovered edge construction

The code walks ancestors for each selected or hovered item, with a `Visited` set to avoid loops. An edge is only added when both its parent and child appear in the current display sequence with parent index preceding child index. Duplicate edges in the same path collection are avoided.

## Unsupported row layouts

`FLabelColumn::ConstructRowWidget` explicitly checks `SSceneOutlinerTreeRow`, and the substitution requires a visible normal `SExpanderArrow` in the expected horizontal box. Native pinned ancestor placeholders and third-party custom rows can therefore remain unchanged.

## Cost boundary

Stem samples only the displayed list rather than the full world. Paths are recalculated at most every **0.05 s**, while normal Slate paint still occurs as necessary.

---

**Verification:** Stem code and the repository's manual-test claims were reviewed; no new hands-on Unreal test has been executed for this documentation pass.

[Design guide](DESIGN.md) · [Implementation references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
