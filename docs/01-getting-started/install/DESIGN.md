# Installation and Compatibility — Design

**Stem v1.0.2 · Unreal Engine 5.8.x · Editor only**

## Requirements

Stem v1.0.2 targets **Unreal Engine 5.8.x, Windows 64-bit**, and runs in the **Editor** only. The repository README records manual testing in UE 5.8.2; other engines/platforms should not be assumed supported.

## Installing through Fab

When an applicable Fab package is available, install it through Epic Games Launcher for a supported engine, enable Stem in **Edit → Plugins** if needed, and restart when prompted. Availability is release-dependent.

## Installing a precompiled release

1. Close Unreal Editor.
2. From [Stem Releases](https://github.com/mippi-the-dork/Stem/releases), select a package matching your engine/platform (when available).
3. Extract the **Stem** plugin folder into `YourProject/Plugins/`.
4. Confirm `YourProject/Plugins/Stem/Stem.uplugin` exists. Do not leave a second nested `Stem/Stem` folder.
5. Reopen the project, enable Stem in **Edit → Plugins**, and restart if requested.

<figure class="doc-media" data-kind="image" data-media-id="install-folder">
  <img src="../../assets/media-placeholder.png" alt="Stem installs as a standard Unreal Engine plugin beneath the project's Plugins directory." loading="lazy">
  <figcaption>Stem installs as a standard Unreal Engine plugin beneath the project's Plugins directory.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Show a Windows File Explorer window at YourProject/Plugins/Stem with Stem.uplugin, Source, Resources, and Config visible; include the folder address bar.</span></figcaption>
</figure>

## Installing from source

Clone [Stem](https://github.com/mippi-the-dork/Stem) to `YourProject/Plugins/Stem`, generate project files if required, and build your project's **Editor** target using the UE 5.8-compatible C++ toolchain. GitHub's automatically generated source ZIP is **not** a precompiled release.

## Confirm it is active

Open the **standard World Outliner**, expand a hierarchy, and look for neutral connector lines beside the native expansion controls. Stem does not open a tool window or add a visible column. Review **Project Settings → Plugins → Stem** if guides are turned off.

## If the guides do not appear

Confirm the plugin is loaded, Show Hierarchy Guides is enabled, the branch is expanded, and you're using the standard Outliner. An already-open Outliner may need to be closed/reopened or the editor restarted after first enabling Stem.

---

[Technical implementation](TECHNICAL.md) · [Getting Started overview](../README.md)
