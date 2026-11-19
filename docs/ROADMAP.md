# Stem Roadmap

**Current documented release:** **Stem v1.0.2**, Unreal Engine 5.8.x · Win64 · Editor only.  
**Roadmap status:** Current functionality is source-verified; future candidates are editorial suggestions for discussion, **not approved feature plans**.

## Timeline

| Milestone | Status | Scope |
| --- | --- | --- |
| **Stem v1.0.2** | Current · released | Connector guides, selected/hovered path highlighting, combined multi-selection paths, adjustable row height and guide appearance |
| **Earlier releases** | Historical · not reconstructed | The inspected repository does not establish a trustworthy feature-by-feature v1.0.0 or v1.0.1 milestone history. No specific chronology is asserted. |
| **Future Stem development** | Not scheduled | Ideas below are candidates to evaluate, not promises, version assignments or implementation commitments |

<figure class="doc-media" data-kind="image" data-media-id="roadmap-timeline"><img src="assets/media-placeholder.png" alt="Timeline separating Stem v1.0.2 current capabilities from uncommitted future candidates" loading="lazy"><figcaption>Stem v1.0.2 establishes the current hierarchy guide and highlighting experience; subsequent improvements have not been assigned a release.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a clean timeline with Stem v1.0.2 shown as Current, earlier versions shown without invented feature claims, and Future explicitly marked Unscheduled/Exploratory. Summarize current functionality without implying a v2.0 release commitment.</span></figcaption></figure>

## Current functionality — v1.0.2

Stem is built around the following shipped capabilities:

- Neutral connector guides in the standard World Outliner.
- Native Actor/Folder expansion and collapse preserved.
- Selected ancestor-path highlighting, including multiple selection.
- Hovered ancestor-path highlighting independent of selection.
- Shared path segments merged by maximum brightness, rather than additive stacking.
- Row Height, Show Hierarchy Guides, Guide Brightness/Thickness, and independent selected/hovered highlight preferences.
- Project configuration persistence; no Actor-level Stem state or runtime module.

See the current [Hierarchy Guides](02-hierarchy-guides/README.md), [Path Highlighting](03-path-highlighting/README.md), and [Appearance and Settings](04-appearance-and-settings/README.md) manuals.

## Future areas to evaluate — not committed

The following are **potential directions**, not an announced Stem roadmap. They should be prioritized only after testing the actual workflow problems.

### More World Outliner compatibility

Evaluate additional supported row types or specialized Outliners only if there is a demonstrated need and an engine-native integration path that preserves selection, expansion and label/widget compatibility.

### Visual accessibility and density

Test contrast, varied editor themes, DPI scaling, very deep nesting and large row counts. Investigate extra settings only when they solve a measurable usability issue rather than growing the settings panel unnecessarily.

### Performance and resilience

Expand native editor tests and stress-test frequent Outliner rebuilds, row-height updates, tab recreation and multi-selection paths on large displayed hierarchies. Preserve Stem's existing preference for sampled visible rows rather than whole-world scans.

## Before committing future work

For any proposed feature, define its user problem, native integration requirements, effect on compact Outliner readability, performance on large displayed trees, compatibility implications and test cases. Confirm that it does not unintentionally modify level or Actor data.

## Explicitly not planned or promised

There is no announced future version number, release date, custom runtime hierarchy system, comprehensive support for every third-party Outliner, or new plugin API promised in the repository materials inspected for this site.

[Source and integration](05-integration-and-support/architecture/TECHNICAL.md) · [Documentation Audit](DOCUMENTATION_AUDIT.md)
