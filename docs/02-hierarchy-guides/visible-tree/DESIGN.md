# Displayed Hierarchies and Limits — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## The hierarchy you see is the hierarchy Stem draws

Stem works from the Outliner's **displayed tree**. It does not open every folder, enumerate every Actor in the level, or fabricate guide paths for rows hidden by a filter.

<figure class="doc-media" data-kind="image" data-media-id="guides-visible-scope">
  <img src="../../assets/media-placeholder.png" alt="Stem's connectors reflect the rows currently visible in the World Outliner." loading="lazy">
  <figcaption>Stem's connectors reflect the rows currently visible in the World Outliner.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a side-by-side screenshot of the same Outliner before and after a search filter or collapsed folder. Highlight the removed/hidden rows and show their connector segments absent from the visible tree.</span></figcaption>
</figure>

## Folder and attached Actor relationships

Both kinds of nesting use the native tree's parent/child references. A visual connector never changes the actual Actor attachment or Folder membership. If you need to reorganize the level, use Unreal's regular Outliner tools.

## Pinned ancestors

Unreal may display pinned ancestor duplicates using special placeholder widgets. Stem intentionally does not treat those as normal hover targets and does not replace unsupported expansion widget layouts.

## Custom Outliners

Editor panels with custom row classes, nested pickers, or specialized expander widgets may not get Stem guides. This is expected: Stem targets the standard World Outliner Actor Browser.

## When a path looks incomplete

First expand the relevant ancestors, then clear filters hiding intermediate rows. If the row is in a custom Outliner, try the standard World Outliner to distinguish compatibility from configuration.

---

[Technical implementation](TECHNICAL.md) · [Hierarchy Guides overview](../README.md)
