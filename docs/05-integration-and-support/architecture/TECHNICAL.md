# Editor Architecture — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Module registration

`FStemModule::StartupModule` registers `OnCreateActorBrowserColumns`, gated against commandlets. `FRegistry` retains weak Outliner and `FLabelColumn` references. The module does not dynamically hot-reload (`SupportsDynamicReloading() == false`).

## Wrapped native label factory

The Actor Browser factory inserts `FRowHeightColumn` and wraps `FSceneOutlinerBuiltInColumnTypes::Label()` with `FLabelColumn`. It invokes the previously registered label factory or SceneOutliner fallback, preserving the native label widget object and forwarding search, sorting and tick functions.

## Deferred expander

`ConstructRowWidget` queues compatible native rows, and a later tick finds the normal `SExpanderArrow`. A maximum of three unsuccessful attempts bounds each pending lookup. Replacement widgets are measured before insertion to avoid zero-width layout jitter.

## Displayed-path computation

`UpdatePaths` calls `SListView::GetItems` via the tree's public base to obtain visible, expanded rows; it derives parent indices/depths from `ISceneOutlinerTreeItem::GetParent`. Selected and hovered paths are calculated at most every 0.05 s.

## Painting and cleanup

`SGuideArrow` paints neutral/highlight guide segments via Slate boxes, reserves the expansion glyph's current rectangle, and paints the inherited triangle on top. At shutdown, the module unregisters delegates, sets `bActive=false`, and restores original arrows only when the expected replacement remains in its slot.

<figure class="doc-media" data-kind="image" data-media-id="architecture-lifecycle"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Stem's row decoration is installed after native row construction and removed safely during editor shutdown."><figcaption>Stem's row decoration is installed after native row construction and removed safely during editor shutdown.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Diagram StartupModule → Actor Browser factory → native row creation → pending expander discovery → guide paint → Stop/restore original arrow. Include weak references and the three-attempt bound.</span></figcaption></figure>

---

**Validation:** Source inspected; new in-editor testing has not been performed for this documentation pass.

[Design guide](DESIGN.md) · [Source references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
