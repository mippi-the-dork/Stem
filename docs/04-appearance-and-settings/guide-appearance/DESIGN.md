# Guide Visibility, Brightness and Thickness — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Three primary options

| Setting | Default | Allowed range or effect |
| --- | ---: | --- |
| Show Hierarchy Guides | On | Toggles Stem's connector drawing |
| Guide Brightness | 0.15 | 0–1; low is subtle, high is brighter |
| Guide Thickness | 2.0 | 1–4 Slate units; scales with editor UI |

Go to **Project Settings → Plugins → Stem**.

<figure class="doc-media" data-kind="image" data-media-id="guide-appearance-variants"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Guide Brightness and Thickness can make the same hierarchy subtle or prominent."><figcaption>Guide Brightness and Thickness can make the same hierarchy subtle or prominent.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Show three side-by-side crops of the same expanded Outliner branch with subtle default guides, brighter guides, and thicker guides. Label the exact values used.</span></figcaption></figure>

## A useful setup order

Keep Show Hierarchy Guides enabled, choose a comfortable Row Height, then tune Guide Brightness. Adjust Thickness only after the line intensity is comfortable. An extremely bright, thick guide in a deep hierarchy may distract from labels.

## What changes immediately?

The preferences change Stem's editor presentation. The lines, brightness and thickness are read when guide widgets paint; there is no new hierarchy asset or level save to manage.

## How it interacts with highlighting

Selected and hovered path brightness are separate values. A selected or hovered path is never darker than the neutral guide it overlays. Even if highlighting is off, neutral hierarchy guides can remain enabled.

## If the controls appear to do nothing

Verify the target hierarchy has expanded visible rows, the setting isn't already at an effective clamp, and you are using a standard World Outliner rather than a specialized picker.

---

[Technical details](TECHNICAL.md) · [Appearance and Settings overview](../README.md)
