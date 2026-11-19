# Stem Documentation Media Inventory

Stem's documentation includes **33 captioned media placements**. Each one has (1) an explanation written for readers and (2) a separate **Capture instructions · Image/GIF** line describing the exact editor state, interaction or technical diagram to produce.

The website reuses genuine images from the existing Stem repository wherever possible: the Stem hero, path-highlighting GIF, both row-height comparisons and the Project Settings screenshot. Additional slots use the supplied neutral placeholder until real media is captured.

## Media status and types

- **Image:** a static screenshot, controlled comparison or source-accurate explanatory diagram.
- **GIF:** a short demonstration of the actual interaction; the placeholder remains a static PNG until that animation is created.
- **Capture instructions:** deliberately visible beneath each figure while preparing the manual; retain the reader-facing caption when replacing the asset.

## Media placements

| Topic | Type | Media ID | Open |
| --- | --- | --- | --- |
| 01-getting-started / README.md | IMAGE | `category-01-getting-started` | [View page](01-getting-started/README.md) |
| 01-getting-started / first-use | GIF | `first-use-highlights` | [View page](01-getting-started/first-use/DESIGN.md) |
| 01-getting-started / first-use | IMAGE | `first-use-render-pipeline` | [View page](01-getting-started/first-use/TECHNICAL.md) |
| 01-getting-started / install | IMAGE | `install-folder` | [View page](01-getting-started/install/DESIGN.md) |
| 01-getting-started / overview | IMAGE | `getting-started-overview` | [View page](01-getting-started/overview/DESIGN.md) |
| 01-getting-started / overview | IMAGE | `architecture-at-a-glance` | [View page](01-getting-started/overview/TECHNICAL.md) |
| 02-hierarchy-guides / README.md | IMAGE | `category-02-hierarchy-guides` | [View page](02-hierarchy-guides/README.md) |
| 02-hierarchy-guides / core | IMAGE | `guides-core` | [View page](02-hierarchy-guides/core/DESIGN.md) |
| 02-hierarchy-guides / core | IMAGE | `guides-geometry` | [View page](02-hierarchy-guides/core/TECHNICAL.md) |
| 02-hierarchy-guides / expansion | GIF | `guides-expansion` | [View page](02-hierarchy-guides/expansion/DESIGN.md) |
| 02-hierarchy-guides / visible-tree | IMAGE | `guides-visible-scope` | [View page](02-hierarchy-guides/visible-tree/DESIGN.md) |
| 02-hierarchy-guides / visible-tree | IMAGE | `visible-tree-indices` | [View page](02-hierarchy-guides/visible-tree/TECHNICAL.md) |
| 03-path-highlighting / combined | GIF | `combined-paths` | [View page](03-path-highlighting/combined/DESIGN.md) |
| 03-path-highlighting / combined | IMAGE | `combined-segment-aggregation` | [View page](03-path-highlighting/combined/TECHNICAL.md) |
| 03-path-highlighting / hovered | GIF | `hovered-path` | [View page](03-path-highlighting/hovered/DESIGN.md) |
| 03-path-highlighting / hovered | IMAGE | `hovered-paint-merge` | [View page](03-path-highlighting/hovered/TECHNICAL.md) |
| 03-path-highlighting / selected | IMAGE | `selected-path` | [View page](03-path-highlighting/selected/DESIGN.md) |
| 03-path-highlighting / selected | IMAGE | `selected-path-flow` | [View page](03-path-highlighting/selected/TECHNICAL.md) |
| 04-appearance-and-settings / configuration | IMAGE | `project-settings-overview` | [View page](04-appearance-and-settings/configuration/DESIGN.md) |
| 04-appearance-and-settings / configuration | IMAGE | `project-settings-flow` | [View page](04-appearance-and-settings/configuration/TECHNICAL.md) |
| 04-appearance-and-settings / guide-appearance | IMAGE | `guide-appearance-variants` | [View page](04-appearance-and-settings/guide-appearance/DESIGN.md) |
| 04-appearance-and-settings / guide-appearance | IMAGE | `guide-paint-geometry` | [View page](04-appearance-and-settings/guide-appearance/TECHNICAL.md) |
| 04-appearance-and-settings / highlighting-settings | IMAGE | `highlight-settings-panel` | [View page](04-appearance-and-settings/highlighting-settings/DESIGN.md) |
| 04-appearance-and-settings / highlighting-settings | IMAGE | `highlight-palette-merge` | [View page](04-appearance-and-settings/highlighting-settings/TECHNICAL.md) |
| 04-appearance-and-settings / row-height | IMAGE | `row-height-comparison` | [View page](04-appearance-and-settings/row-height/DESIGN.md) |
| 04-appearance-and-settings / row-height | IMAGE | `row-height-layout` | [View page](04-appearance-and-settings/row-height/TECHNICAL.md) |
| 05-integration-and-support / architecture | IMAGE | `editor-architecture` | [View page](05-integration-and-support/architecture/DESIGN.md) |
| 05-integration-and-support / architecture | IMAGE | `architecture-lifecycle` | [View page](05-integration-and-support/architecture/TECHNICAL.md) |
| 05-integration-and-support / compatibility | IMAGE | `compatibility-native-outliner` | [View page](05-integration-and-support/compatibility/DESIGN.md) |
| 05-integration-and-support / troubleshooting | IMAGE | `troubleshoot-guides` | [View page](05-integration-and-support/troubleshooting/DESIGN.md) |
| 05-integration-and-support / troubleshooting | IMAGE | `troubleshoot-state-sequence` | [View page](05-integration-and-support/troubleshooting/TECHNICAL.md) |
| 05-integration-and-support / updating | IMAGE | `support-installation` | [View page](05-integration-and-support/updating/DESIGN.md) |
| ROADMAP.md | IMAGE | `roadmap-timeline` | [View page](ROADMAP.md) |

## Replacement workflow

1. Open the linked page and follow the **Capture instructions** beneath the media. Capture real Unreal Editor 5.8 UI, or create a clearly labeled source-accurate diagram for Technical topics.
2. Name the final file `docs/assets/media/<media-id>.png` for images or `.gif` for animations.
3. Replace the figure's `<img src>` with the corresponding relative file path. Keep its reader-facing caption and refine alt text to match the final framing.
4. Test image sizing, captions and GIF motion on desktop and mobile, update the registry and document the capture's engine/plugin version.
5. Do not replace genuine existing media merely because a placeholder inventory entry exists.

See the machine-readable [Media Slot Registry](assets/media-slots.json).
