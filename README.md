# Stem

Stem improves readability in Unreal Engine's World Outliner with visual hierarchy guides, selected and hovered path highlighting, and configurable row height. Adjustable guide brightness and thickness let you tune the hierarchy display to your workspace.

**Compatibility:** Tested in Unreal Engine 5.8.2 on Windows (64-bit).

Stem works in the standard World Outliner without adding a visible column. It requires no engine modifications and has no dependency on Motion Design, Focus, Chroma, Origin, or Surface.

## Installation

1. Download the Stem plugin ZIP from the repository's release **Assets**.
2. Close Unreal Editor and extract the `Stem` folder into your project's `Plugins` folder. Create that folder if it doesn't exist.
3. Confirm the descriptor is located at `YourProject/Plugins/Stem/Stem.uplugin`.
4. Open your project and enable **Stem** under **Edit > Plugins**.
5. Restart the editor if prompted.

For a source installation, regenerate your C++ project files and build the project's **Development Editor** target using the matching engine version. GitHub's automatically generated source archives may require compilation; use the plugin ZIP attached to a release for the packaged distribution.

## Usage

Hierarchy guides appear automatically beside the expansion arrows in **Item Label**. They connect folders and attached actors, including nested assemblies built with Origin Anchors.

- **Select an item** to brighten its path to visible ancestors.
- **Select multiple items** to trace their combined ancestor paths. Shared segments retain the same brightness.
- **Hover a row** to temporarily brighten its path without changing selection. Move away to clear the hover highlight.
- Expand and collapse branches normally, including Unreal's existing **Shift-click** expansion behavior.

Highlights follow the connectors through intervening rows without brightening unrelated sibling connectors. Where selection and hover overlap, the brighter configured value wins. Guides leave a gap around expansion triangles to keep them readable.

## Settings

Open **Project Settings > Plugins > Stem**. Guides and both highlighting options are enabled by default.

| Setting | Default | Description |
| --- | --- | --- |
| Row Height | 26.5 | World Outliner row height in pixels. Values below Unreal's native row height never shrink the rows below the native minimum. |
| Show Hierarchy Guides | On | Shows or hides all Stem guides. |
| Guide Brightness | 0.15 | Brightness of regular guides, from 0 to 1. |
| Guide Thickness | 2 | Stroke width, adjustable from 1 to 4 Slate units. |
| Highlight Selected Paths | On | Highlights selected items' ancestor paths. |
| Selected Path Brightness | 0.65 | Brightness of selection highlights. |
| Highlight Hovered Path | On | Highlights the hovered row's ancestor path. |
| Hovered Path Brightness | 0.40 | Brightness of hover highlights. |

Changes apply during use. Changing Row Height triggers Stem settings' editor change handler and performs a full refresh of open standard World Outliners so spacing updates immediately. Settings are stored through the project's `Config/DefaultStem.ini`. Explicitly saved values take precedence over defaults. Thickness scales with the editor UI, and highlights never dim the regular guides.

All guides remain neutral gray. Stem does not use Chroma colors for its lines.

## Compatibility and scope

Stem preserves the existing label content and normal Outliner controls, including actor icons, renaming, selection, and drag-and-drop. Row height is contributed by a hidden layout-only column so the native Item Label widget remains untouched. It can operate alongside the suite's Outliner plugins without adding visible columns or changing their visible column order.

- Guides follow the displayed hierarchy. Collapsed or filtered-out portions are not drawn.
- Each Outliner uses its own selection and hover state.
- Pinned ancestor duplicates retain their native presentation and do not act as hover targets for Stem.
- Custom Outliner implementations and custom expansion widgets are outside the supported integration.
- Existing Outliner tabs may need reopening after activation. Restart the editor after code changes.

Stem changes editor presentation only. It does not modify actors, folders, attachments, or saved levels and contains no runtime module.

## Validation

Stem has been manually tested in Unreal Engine 5.8.2 for hierarchy guides, appearance controls, row height, selected and hovered path highlighting, expansion/collapse behavior, selection, and standard World Outliner interaction.

Clean-project installation, plugin packaging, and packaged-game validation remain unverified. Compatibility with every third-party Outliner customization is not guaranteed.

## Documentation

[Doc/Sources.md](Doc/Sources.md) records implementation references and the integration approach. `Config/FilterPlugin.ini` includes this README and the Doc folder in plugin packaging.
