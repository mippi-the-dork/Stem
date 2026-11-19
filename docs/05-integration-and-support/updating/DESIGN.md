# Updates and Support — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Current documented version

The repository's `Stem.uplugin` reports **v1.0.2** and Unreal Engine **5.8.0** targeting, with **Win64 Editor** support. The README records UE **5.8.2** as a tested version. The latest source may change over time; match the package/release you're actually installing.

## Updating a precompiled installation

1. Close Unreal Editor.
2. Download the compatible version from [Releases](https://github.com/mippi-the-dork/Stem/releases) when available.
3. Replace the complete **YourProject/Plugins/Stem** folder rather than merging files from different releases.
4. Reopen the project, check the plugin version, and inspect a standard World Outliner.

## Updating a source checkout

Pull the intended branch/tag and rebuild the project's Editor target. If upgrading Unreal itself, recompile against the new supported editor API rather than copying binaries between engine versions.

## Settings during an update

Stem preferences are stored as project configuration, not in Actor packages. Replacing plugin files should not require deleting project level data. Check your project config when moving between versions.

## Getting support

Use [Stem GitHub Issues](https://github.com/mippi-the-dork/Stem/issues). Include exact Stem and Unreal versions, whether installed through source or a release, the native/custom Outliner type, affected setting, steps, and relevant screenshot/log.

<figure class="doc-media" data-kind="image" data-media-id="support-installation"><img src="../../assets/media-placeholder.png" loading="lazy" alt="A Stem installation contains Stem.uplugin at the top level of the project's Plugins/Stem directory."><figcaption>A Stem installation contains Stem.uplugin at the top level of the project's Plugins/Stem directory.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Capture File Explorer at YourProject/Plugins/Stem with Stem.uplugin, Source, Config and Resources visible; include the address bar and no extra nested Stem folder.</span></figcaption></figure>

## Future updates

Consult the [Roadmap](../../ROADMAP.md) for explicitly confirmed current capabilities and any future directions. Do not treat exploratory ideas as shipped features or guaranteed release commitments.

---

[Technical details](TECHNICAL.md) · [Integration and Support overview](../README.md)
