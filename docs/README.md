# Stem Documentation

**Stem v1.0.2 · Unreal Engine 5.8.x · Windows 64-bit · Editor-only**

Stem improves the readability of Unreal Engine's **World Outliner**. It draws connector guides through nested folders and attached Actor hierarchies, highlights selected and hovered ancestor paths, and lets you adjust row height and guide appearance. It preserves the original hierarchy and Unreal's normal Outliner controls.

![Stem hierarchy guides and highlighting in the World Outliner](assets/Stem-Hero.png)

*Stem clarifies parent-child relationships directly inside the World Outliner, without changing level content.*

## What can I do with Stem?

**Trace nested hierarchies.** Follow neutral vertical and horizontal connectors through the folders and Actor attachments currently displayed in the Outliner.

**Follow selected Actors.** Selecting a deeply nested row brightens the displayed path back to its ancestors. Multiple selections show combined paths without becoming artificially brighter where they overlap.

**Preview other branches.** Hover a row to temporarily highlight its ancestor path while keeping the existing selection.

**Adjust readability.** Increase row height, guide thickness and base/selected/hovered brightness through Project Settings.

## Get started in three steps

1. [Install Stem](01-getting-started/install/DESIGN.md) and enable it for an Unreal Engine 5.8.x Windows Editor project.
2. [Try Stem](01-getting-started/first-use/DESIGN.md) in a level with nested folders or attached Actors; expand the hierarchy, select a child and hover a different row.
3. [Tune the appearance](04-appearance-and-settings/README.md) under **Project Settings → Plugins → Stem**.

## Which guide should I read?

**Design** pages teach the controls and expected editor behavior: what you see, how you use it, practical examples and common problems. **Technical** pages describe how Stem uses Unreal's native Slate/SceneOutliner APIs, derives paths and handles lifecycle and limitations.

## Explore the manual

| Section | Topics | What you'll learn |
| --- | ---: | --- |
| [01. Getting Started](01-getting-started/README.md) | 3 | Installation, purpose and first-use walkthrough |
| [02. Hierarchy Guides](02-hierarchy-guides/README.md) | 3 | Connector lines, native expansion and displayed-row limits |
| [03. Path Highlighting](03-path-highlighting/README.md) | 3 | Selected paths, hover feedback and shared-path behavior |
| [04. Appearance and Settings](04-appearance-and-settings/README.md) | 4 | Row height, guide appearance, highlighting and configuration |
| [05. Integration and Support](05-integration-and-support/README.md) | 4 | Editor architecture, compatibility, troubleshooting and updates |

## Understand Stem's limits

Stem only draws the **currently displayed Outliner hierarchy**; collapsed/filtered rows do not appear. Pinned ancestor duplicates and specialized custom row layouts are not guaranteed to receive normal guide/highlight behavior. It is a presentation tool, not a new Outliner column, Actor editor, runtime component or packaged game feature.

## Version and future development

The [Roadmap](ROADMAP.md) identifies the documented v1.0.2 baseline, what can be substantiated historically, and possible future areas that are **not yet committed**. The [Documentation Audit](DOCUMENTATION_AUDIT.md) and [Verification Matrix](VERIFICATION_MATRIX.md) track remaining gaps and real testing status.

## Project and support

- [Stem source repository](https://github.com/mippi-the-dork/Stem)
- [Releases](https://github.com/mippi-the-dork/Stem/releases)
- [Issues and feedback](https://github.com/mippi-the-dork/Stem/issues)
- [MIT License](https://github.com/mippi-the-dork/Stem/blob/main/LICENSE)

**Documentation basis:** The current Stem C++ implementation, v1.0.2 descriptor, existing README and Doc/Sources.md. Existing manual testing is attributed to the repository; this documentation pass does not claim new editor/browser test results.
