# Compatibility and Limitations — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Native row filter

`FLabelColumn::ConstructRowWidget` checks `Row.GetType()=="SSceneOutlinerTreeRow"`. `FindArrow` seeks the first expected native `SExpanderArrow` beneath the correct `SHorizontalBox`; pinned placeholders are deliberately skipped when not visible.

## Resource management

Pending entries, installed row widgets and Outliner references are weak where appropriate, so destroyed rows do not permanently retain a widget. `FRegistry` removes stale weak pointers during refresh. Original arrows are stored only for installed replacements.

## Compatibility with label decorators

The module's label factory returns the original native label content; the replacement targets the expansion widget's slot. This avoids changing what an independent decorator sees as the label type. No guarantee can be made about the ordering or internals of arbitrary third-party plugins.

## Dynamic reload and shutdown

`SupportsDynamicReloading()` returns false. `ShutdownModule()` removes column registration and calls `Stop()` for live decorated columns, which restores the previous expander when safe. Late-created tabs during unload are out of scope.

## Engine-source constraint

Stem operates entirely through plugin/editor APIs and public Slate access. No Unreal Engine source modification, memory offset patch or private-field access is required.

---

**Validation:** Source inspected; new in-editor testing has not been performed for this documentation pass.

[Design guide](DESIGN.md) · [Source references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
