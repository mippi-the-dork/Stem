# Selected Path Highlighting — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Select to follow a path

Click an Actor or Folder row in the standard World Outliner. Stem brightens the guide segments connecting that row to its **visible** ancestors. The selection itself is Unreal's native selection; Stem only paints its path.

<figure class="doc-media" data-kind="image" data-media-id="selected-path"><img src="../../assets/media-placeholder.png" loading="lazy" alt="A selected Actor's visible ancestor path stands out from the surrounding neutral guides."><figcaption>A selected Actor's visible ancestor path stands out from the surrounding neutral guides.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Capture an expanded Outliner with a single deep child selected. Show its entire guide path through several named ancestor rows and neutral guides on unselected branches.</span></figcaption></figure>

## Step-by-step example

With an Outliner like **Environment → Building → Interior → Furniture → Chair**, select Chair. Its displayed chain back toward Environment becomes easier to trace. Collapse Interior and the hidden descendants no longer contribute visible segments.

## Settings to inspect

Under **Project Settings → Plugins → Stem**, ensure **Highlight Selected Paths** is on and **Selected Path Brightness** is perceptibly above Guide Brightness. Defaults are **On**, **0.65** and **0.15**, respectively.

## Common questions

**Why doesn't the highlight reach every ancestor?** The Outliner may not display all intervening rows because of collapse, filters or an unsupported custom hierarchy view.

**Does selecting through Stem change something?** No. Selection is native Unreal behavior. Stem highlights the connector path for the selection it observes.

## Multiple selection

When selecting several Actors, each visible ancestor path may be highlighted. Shared guide segments stay at one consistent brightness, not the sum of the number of selections. See [Multi-Selection](../combined/DESIGN.md).

---

[Technical details](TECHNICAL.md) · [Path Highlighting overview](../README.md)
