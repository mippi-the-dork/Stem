# Installation and Compatibility — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Descriptor contract

`Stem.uplugin` identifies `VersionName: 1.0.2`, `EngineVersion: 5.8.0`, `Modules[0].Type: Editor`, `LoadingPhase: PostEngineInit`, and `PlatformAllowList: ["Win64"]`. These describe targeting, not automatic verification of all UE 5.8 patch releases.

## Build and module dependencies

The plugin's build rules declare `Core`, `CoreUObject`, `Engine`, `DeveloperSettings` and private Slate/SceneOutliner dependencies. The plugin is intentionally editor-only; game targets must not depend on this module.

## Startup behavior

`FStemModule::StartupModule` returns early for commandlets and registers a delegate for Actor Browser columns. A fresh compatible Outliner creates both the hidden height contributor and the label decorator. Reopening an existing tab can be necessary when registration occurs after its construction.

## Deployment and source scope

The source tree and binary package are different delivery mechanisms. Build source installations with the target Unreal Editor toolchain; do not infer that a repository source archive contains prebuilt DLLs. No engine source modification is required.

For module registration details, see [Architecture Technical](../../05-integration-and-support/architecture/TECHNICAL.md).

---

**Verification:** Stem code and the repository's manual-test claims were reviewed; no new hands-on Unreal test has been executed for this documentation pass.

[Design guide](DESIGN.md) · [Implementation references](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
