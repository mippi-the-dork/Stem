# Stem sources and implementation references

Target: Unreal Engine 5.8.2. Engine source references were supplied by Mippi. This document identifies the references used to implement Stem; it does not redistribute engine files or grant rights to Epic's code or assets. Stem requires no engine source modifications.

## Design reference

Motion Design's Outliner provided the reference for visual tree connectors. In `SAvaOutlinerLabelItem.cpp`, it constructs `SAvaOutlinerExpanderArrow` with 12-unit indentation and `ShouldDrawWires(true)`. The custom expander's `OnPaint` draws branch lines using row hierarchy information.

Stem applies this interaction to the standard World Outliner. It has no Avalanche or Motion Design dependency.

## Standard Outliner integration

- **SOutlinerTreeView.cpp:** native rows create their expansion widget after the label-column content. This establishes the insertion timing, 12-unit indentation, and separate hidden placeholders used by pinned rows.
- **SExpanderArrow.h/.cpp:** supplies expansion-button construction, normal and Shift-click behavior, indentation, arrow brushes, and the reference geometry for native tree connectors. Stem's subclass retains the button behavior while painting its own guides.
- **ISceneOutlinerColumn.h, SceneOutlinerModule, and SceneOutlinerPublicTypes:** expose the label-column factory and column interfaces. Stem wraps the existing factory and forwards row content, search, sorting, and tick behavior.
- **Slate widget children and horizontal-box slot APIs:** identify the exact native expander and replace only its slot after row construction. The original arrow is retained for restoration. Label widgets remain unchanged, allowing other decorators such as Chroma to recognize them.

No private field access or access-control bypasses are used. Custom row layouts and custom expansion widgets are not replaced.

## Guide drawing and path highlighting

- **ITableRow hierarchy queries:** provide nesting wires, last-child state, expansion state, and displayed row indices.
- **SListView::GetItems**, accessed through the Outliner tree's public base class: supplies the expanded display order, including intervening rows. Root items alone would not provide enough information to trace a connector through the tree.
- **ISceneOutlinerTreeItem::GetParent:** supplies ancestor relationships. Selection comes from the corresponding Outliner tree; hover comes from its realized rows.
- **FSlateDrawElement::MakeBox:** draws neutral guide segments with configurable width and opacity. Parent-child spans determine which vertical portions and horizontal connectors receive highlights. Shared paths merge brightness rather than adding it repeatedly.
- **UDeveloperSettings:** `Config=Stem` and `DefaultConfig` store appearance and highlighting preferences. Guides, selected-path highlighting, and hovered-path highlighting default on.

The displayed tree is sampled at most every 0.05 seconds for path updates. Stem does not enumerate world actors to calculate these paths. Colors remain neutral; Chroma color integration is intentionally excluded.

## Layout and triangle fixes

**Expansion layout:** replacing an expander after the normal layout prepass could leave it temporarily unmeasured, shifting icons and labels left. Stem measures the replacement with `SlatePrepass` before insertion, then invalidates and measures the containing layout using the row's layout scale. Mippi confirmed this removed the visible jump.

**Triangle readability:** drawing the native triangle above the guides still allowed lines to show through its transparent brush background. Stem excludes the arrow brush's bounds, plus a small gap, from both baseline and highlighted guide rectangles. The exclusion uses current layout and brush dimensions rather than previous-frame geometry. Mippi confirmed the overlap was resolved.

## Lifecycle and compatibility

Rows, replacement arrows, and parent boxes are tracked through weak pointers. Original arrow widgets are retained while their replacements remain alive. Only newly generated native rows are searched, with bounded retries.

Disabling guides suppresses drawing. Shutdown removes the column-registration callback and restores original arrows where the slot still contains Stem's replacement. Dynamic module reload is disabled.

The integration adds no columns and does not replace global label-column registration. It leaves label content, actor/folder data, selection actions, and attachment relationships intact. Stem contains an editor-only module.

## Validation record

Mippi confirmed the editor build and initial hierarchy behavior, followed by working appearance controls and selected/hovered path highlighting. The expansion-position jump and triangle-overlap fixes were each tested and confirmed.

Clean-project installation, plugin packaging, packaged-game builds, and exhaustive compatibility with third-party Outliner customizations remain separate validation tasks.
