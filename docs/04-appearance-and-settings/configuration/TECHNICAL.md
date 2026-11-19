# Project Settings and Persistence — Technical

**Stem v1.0.2 · Source-reviewed implementation**

## Configuration class

`UStemSettings : UDeveloperSettings` is marked `UCLASS(Config=Stem, DefaultConfig, meta=(DisplayName="Stem"))`. Its section is `Stem` and settings category is `Plugins`. Fields have `UPROPERTY(Config, EditAnywhere)` and editor metadata for value bounds or conditions.

## Immediate changes

`PostEditChangeProperty` refreshes registered Outliners only when `RowHeight` changes. Other settings are read during guide painting and path sampling.

## Data and source control

Preferences belong to configuration, not per-Actor metadata. Unlike editor-per-user settings, `Config=Stem,DefaultConfig` is intended for project-level config. The exact config file/source-control policy depends on Unreal's settings storage and the project setup.

<figure class="doc-media" data-kind="image" data-media-id="project-settings-flow"><img src="../../assets/media-placeholder.png" loading="lazy" alt="Stem preferences feed row-height layout, neutral guide paint and selected/hovered path sampling."><figcaption>Stem preferences feed row-height layout, neutral guide paint and selected/hovered path sampling.<span class="media-capture-instructions"><strong>Capture instructions · Image:</strong> Create a diagram showing UStemSettings with three groups: Row Height → FullRefresh/minimum row layout; Show/Guide Brightness/Thickness → guide paint; Selected/Hovered controls → FGuidePaths sample and highlight paint.</span></figcaption></figure>

## No packaged integration

The Editor module reads the preferences during editor use. The project-level config may exist in source control, but it does not create a Stem runtime component or packaged gameplay requirement.

---

**Verification:** The public source and published manual-test notes were reviewed; this documentation pass has not independently run the Unreal Editor.

[Design guide](DESIGN.md) · [Implementation sources](https://github.com/mippi-the-dork/Stem/blob/main/Doc/Sources.md)
