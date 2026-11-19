# Expansion and Collapse — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Native expansion remains native

Stem keeps the World Outliner's usual triangle controls and expansion behavior. Expand or collapse a folder exactly as you would without the plugin. Stem only changes how the adjacent connector lines appear.

<figure class="doc-media" data-kind="gif" data-media-id="guides-expansion">
  <img src="../../assets/media-placeholder.png" alt="Expansion and collapse reveal only the guide segments belonging to the currently displayed rows." loading="lazy">
  <figcaption>Expansion and collapse reveal only the guide segments belonging to the currently displayed rows.<span class="media-capture-instructions"><strong>Capture instructions · GIF:</strong> Record opening and closing a nested folder and a parent Actor using the native expansion triangles. Show connectors appearing and disappearing while row labels remain stable.</span></figcaption>
</figure>

## Working with nested folders

Expand a parent folder to reveal a new set of child rows. Continue expanding nested folders to expose more connector segments. Collapsing a parent hides its descendants, so those descendants cannot have visible ancestor paths drawn in that collapsed view.

## Expansion controls remain clear

Stem leaves space around the expansion triangles, rather than drawing wires through the icon. This is especially useful on dense rows where line thickness is increased.

## After adjusting row height

If a taller Row Height setting changes spacing, expand and collapse branches again to confirm the guides remain aligned. If an already-open Outliner was constructed before Stem initialized, reopen the tab or restart Unreal.

## What isn't promised

Stem does not add a new expansion mode, custom hierarchy search, or a different drag/drop/selection policy. It forwards native behavior, including Unreal's own modifier-based expansion shortcuts.

---

[Technical implementation](TECHNICAL.md) · [Hierarchy Guides overview](../README.md)
