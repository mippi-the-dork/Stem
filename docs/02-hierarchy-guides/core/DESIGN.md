# Hierarchy Guide Lines — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## What guides show

Stem draws subtle vertical and horizontal connectors next to the Outliner's existing expansion controls. The lines visually link displayed **Folders** and **attached Actors** through their nesting levels.

<figure class="doc-media" data-kind="image" data-media-id="guides-core">
  <img src="../../assets/Stem-Hero.png" alt="Hierarchy guides clarify branches and parent-child relationships in a dense World Outliner." loading="lazy">
  <figcaption>Hierarchy guides clarify branches and parent-child relationships in a dense World Outliner.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Capture the same expanded Outliner hierarchy with Stem's neutral guides visible and a mixture of folders, Actor rows, leaf nodes and branching parents. Ensure several levels of indentation can be traced.</span></figcaption>
</figure>

## Follow a branch

Find a child row and trace its short horizontal connector to the vertical line for its parent depth. Follow that line upward until it meets the displayed ancestor. The guide is a visual aid: the tree itself is still Unreal's existing hierarchy.

## Read a collapsed branch

When you collapse a folder or an Actor with children, Stem leaves Unreal's usual collapsed row and expansion triangle. The hidden children no longer contribute visible guide segments. Expand the branch again to see its displayed descendants.

## What you can adjust

- **Show Hierarchy Guides** turns connector drawing on/off.
- **Guide Brightness** changes the neutral line opacity.
- **Guide Thickness** adjusts line stroke width and respects Slate UI scale.
- **Row Height** adds spacing if rows feel too crowded.

These settings are under **Project Settings → Plugins → Stem**. They affect presentation, not attachments or stored Actor data.

## Why a guide may be missing

Confirm that the row is displayed in a compatible standard Outliner and the relevant branch is expanded. Custom expander widgets, pinned ancestor duplicates, and filtered-out rows do not necessarily receive the same decoration.

---

[Technical implementation](TECHNICAL.md) · [Hierarchy Guides overview](../README.md)
