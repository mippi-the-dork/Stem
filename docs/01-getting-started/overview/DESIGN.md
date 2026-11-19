# What Stem Does — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Purpose

Stem improves readability in Unreal Engine's **standard World Outliner**. It paints tree-connector guides beside the native expansion arrows, highlights the visible ancestor paths of selected and hovered rows, and offers more breathing room through adjustable row height.

<figure class="doc-media" data-kind="image" data-media-id="getting-started-overview">
  <img src="../../assets/Stem-Hero.png" alt="Stem reveals the parent-child structure of a dense World Outliner without changing any Actors." loading="lazy">
  <figcaption>Stem reveals the parent-child structure of a dense World Outliner without changing any Actors.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Capture one expanded Unreal World Outliner with multiple nested folders and attached Actors, with Stem guides visible and one selected Actor. Keep folder names, guides, and indentation easy to read.</span></figcaption>
</figure>

## Problems it helps solve

- **Finding the parent of an Actor:** Follow connector lines toward the top of the visible hierarchy.
- **Reading deep nesting:** Guides distinguish adjacent branches, especially when many Actor and Folder labels are similarly indented.
- **Tracking several selections:** Selected paths become brighter, without repeatedly adding brightness on shared portions.
- **Inspecting without selecting:** Hover another row to trace its path independently.
- **Making rows easier to scan:** Increase row height without introducing a visible Stem column.

## Typical workflow

Expand the folders you're working in, select a deeply nested Actor, and follow its highlighted guides toward the visible ancestors. Hover a different Actor to preview its path while maintaining the original selection. If the Outliner feels cramped, open **Project Settings → Plugins → Stem** and adjust Row Height.

## What Stem does not do

Stem does **not** reparent Actors, create folders, alter attachments, modify level packages, or run in packaged gameplay. It is a presentation enhancement for the existing Outliner, not a new hierarchy system.

## Choose your next topic

Start with [Installation](../install/DESIGN.md) or [First Use](../first-use/DESIGN.md), then explore [Hierarchy Guides](../../02-hierarchy-guides/README.md) and [Path Highlighting](../../03-path-highlighting/README.md).

---

[Technical implementation](TECHNICAL.md) · [Getting Started overview](../README.md)
