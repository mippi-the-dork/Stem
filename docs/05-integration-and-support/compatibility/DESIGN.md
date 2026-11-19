# Compatibility and Limitations — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Supported environment

The current plugin descriptor targets **Unreal Engine 5.8.x and Win64**. The README reports manual testing in **UE 5.8.2**. Stem contains only an Editor module, so there is no Stem gameplay system or runtime Actor.

## Standard World Outliner support

Stem decorates the native Actor Browser label/expander. It preserves native selection, expansion, drag/drop, sorting, icons and labels; custom Outliner implementations may not expose the row widget structure it expects.

## Known boundaries

| Situation | Expected behavior |
| --- | --- |
| Branch collapsed or filtered | Hidden descendants don't have visible guide segments |
| Native pinned ancestor duplicate | May retain Unreal's placeholder/presentation rather than normal hover decoration |
| Specialized Scene Outliner | Custom expander/row may be unrecognized |
| Existing tab when plugin first activates | Reopen the tab or restart the editor if guides don't appear |
| Show Hierarchy Guides off | No Stem guide rendering |
| Row Height below native minimum | Native minimum still determines effective height |
| Packaged game | No Stem Editor module runtime behavior |

## Performance expectation

The plugin samples displayed Outliner rows for path updates, not every Actor in the world; this does not prove performance for all project sizes. Complex editor configurations and many visible rows should still be evaluated in your production environment.

<figure class="doc-media" data-kind="image" data-media-id="compatibility-native-outliner"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Stem decorates the standard World Outliner and leaves specialized custom row layouts outside its guaranteed support."><figcaption>Stem decorates the standard World Outliner and leaves specialized custom row layouts outside its guaranteed support.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Show one supported standard World Outliner with guide lines, beside a schematic example of a custom picker Outliner labeled as unsupported/untested rather than implying it is broken.</span></figcaption></figure>

## Compatibility claims

Do not assume another engine version, platform or third-party label decorator is supported just because the plugin compiles. Test the actual editor combination before treating it as validated.

---

[Technical details](TECHNICAL.md) · [Integration and Support overview](../README.md)
