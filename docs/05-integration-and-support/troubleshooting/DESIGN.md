# Troubleshooting and FAQ — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Guides are missing

Confirm **Edit → Plugins → Stem** is enabled, then open **Project Settings → Plugins → Stem** and turn on **Show Hierarchy Guides**. Expand a normal folder or attached Actor hierarchy; there are no visible connector segments for collapsed-out child rows.

If Stem was just enabled, **close and reopen the World Outliner** or restart the editor. It does not expose a visible tool window or ordinary column header.

<figure class="doc-media" data-kind="image" data-media-id="troubleshoot-guides"><img src="../../assets/media-placeholder.png" loading="lazy" alt="The standard Outliner displays subtle guide lines when Show Hierarchy Guides is enabled."><figcaption>The standard Outliner displays subtle guide lines when Show Hierarchy Guides is enabled.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Capture an expanded native World Outliner with Stem's neutral guides visible and the Show Hierarchy Guides setting enabled in Project Settings, preferably side by side.</span></figcaption></figure>

## Selected path is not bright enough

Check **Highlight Selected Paths**. Increase Selected Path Brightness above Guide Brightness. Defaults are 0.65 and 0.15; when both are nearly equal, selection highlighting may be hard to distinguish.

## Hover highlighting doesn't appear

Check **Highlight Hovered Path** and **Hovered Path Brightness**. Move the pointer across a normal realized row; pinned ancestor duplicates and custom row widgets aren't guaranteed to behave like native rows.

## Row Height looks unchanged

Stem never reduces below native minimum row height. Increase the requested Row Height enough to exceed that baseline, and verify the standard World Outliner refreshes. The setting range is 20–64, UI slider 20–40.

## The tree seems incomplete

Check for collapsed branches and Outliner filters; Stem draws only displayed rows. It never creates missing parent-child relationships.

## The plugin changed my level?

Stem does not mutate Actor, Folder or attachment data. Check unrelated native edits before attributing level/package changes to Stem.

## Reporting a bug

Record Stem/Unreal version, project configuration, standard/custom Outliner context, exact steps, expected versus observed guide/path behavior, screenshots and Output Log. If another plugin decorates the Item Label/expander, identify it in the report.

---

[Technical details](TECHNICAL.md) · [Integration and Support overview](../README.md)
