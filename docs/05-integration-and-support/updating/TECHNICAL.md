# Updates and Support — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Version metadata

`Stem.uplugin` has `Version: 1`, `VersionName: 1.0.2`, `EngineVersion: 5.8.0`, and a single `Editor` module with `Win64` allowlist. There are no runtime modules.

## Build requirements

The Build.cs uses core UObject/Engine/DeveloperSettings dependencies, with private Slate/SlateCore/SceneOutliner usage. Building against another engine version or platform requires compatibility testing of the editor integration points, not just changing descriptor strings.

## Critical maintenance points

- Verify actor browser label factory registration and hidden column behavior after engine updates.
- Test `SSceneOutlinerTreeRow` and `SExpanderArrow` detection, expansion glyph clearance, and the deferred installation prepass.
- Confirm weak references and cleanup still work when tabs are closed or the Editor unloads.
- Test Row Height refresh, displayed path traversal, and max-brightness overlap after native Outliner changes.

## Release documentation

If a future release changes UI defaults, native integration or supported engine versions, update the corresponding Design and Technical pages and verification results. GitHub `main` source links follow current development; for old release documentation, prefer tagged/source commit links when a suitable tag exists.

No previous Stem version history beyond what the repository supports is asserted here.

---

**Validation:** Source inspected; new in-editor testing has not been performed for this documentation pass.

[Design guide](DESIGN.md) · [Source references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
