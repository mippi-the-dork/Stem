# Expansion and Collapse — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Native expansion widget substitution

`FLabelColumn` creates the original Item Label content and later finds `SExpanderArrow` in the row's expected indentation slot. It keeps the original arrow pointer for restoration and inserts the custom `SGuideArrow`, which inherits normal expansion logic.

## Layout sequencing

Before insertion, Stem measures the replacement via `SlatePrepass(LayoutScale)`. After insertion it invalidates and remeasures the containing box. This prevents the AutoWidth replacement from briefly presenting a zero-width child and pulling labels left.

## Paint ordering

Normal wires and highlights render on lower layers; `SExpanderArrow::OnPaint` paints the native triangle above them. A brush-derived rectangle, plus a gap, is excluded from both line passes.

## Safe restoration

During module shutdown, Stem restores an original expander only if the parent still owns the expected custom widget at slot zero. It does not blindly replace widgets restructured by another tool.

See [Lifecycle and Compatibility](../../05-integration-and-support/compatibility/TECHNICAL.md).

---

**Verification:** Stem code and the repository's manual-test claims were reviewed; no new hands-on Unreal test has been executed for this documentation pass.

[Design guide](DESIGN.md) · [Implementation references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
