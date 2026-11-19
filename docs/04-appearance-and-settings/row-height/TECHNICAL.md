# Row Height and Spacing — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Hidden layout-only column

`FRowHeightColumn` registers a column ID `StemRowHeightColumn` but declares its header Hidden and width 1.0. It contributes only an `SBox` with `MinDesiredHeight`, not a visible UI column.

## Effective height calculation

`Max(FSceneOutlinerDefaultTreeItemMetrics::RowHeight(), UStemSettings::RowHeight)` is used for the desired height. The setting's configured default is 26.5 with metadata clamp **20–64**.

<figure class="doc-media" data-kind="image" data-media-id="row-height-layout"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Stem's hidden layout-only column increases row height without replacing the label widget."><figcaption>Stem's hidden layout-only column increases row height without replacing the label widget.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create an Outliner row anatomy diagram showing the unchanged native label, hidden StemRowHeightColumn SBox, requested minimum height and Unreal's native minimum competing through Max().</span></figcaption></figure>

## Live refresh

`UStemSettings::PostEditChangeProperty` calls `Stem::RefreshOutlinersForRowHeight()` when Row Height changes. A weak registry iterates registered standard Outliners and calls `FullRefresh()`.

## Separation from guide paint

Guide Thickness and Brightness affect rendering; Row Height affects Slate layout. The main label widget is still supplied by the original label-column factory, preserving native icon, search, selection and drag/drop behavior.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
