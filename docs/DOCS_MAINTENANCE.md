# Maintaining Stem Documentation

This site is published from the Stem repository's `/docs` directory using the same visual design as the Focus and Mippi portfolio documentation. It uses static Markdown and a lightweight client-side renderer.

## Page roles

- **DESIGN.md** is the user manual: purpose, visible controls, workflows, expected result, relevant limitations, screenshots/GIFs.
- **TECHNICAL.md** explains implementation: Unreal Slate widgets, Outliner tree data, module lifecycle, settings ownership, source references and performance boundaries.
- Category **README.md** pages should explain the topic and guide users to its pages, not exist only as empty link directories.
- **ROADMAP.md** distinguishes implemented features from unapproved ideas. Do not invent version history or dates.

## Editing and publication

1. Inspect the current code/README before changing claims about behavior.
2. Update both sides of the relevant Design/Technical pair.
3. Update category and root README tables if adding/removing a topic; the JS site parses these navigation tables.
4. Check Markdown relative links, image paths, HTML captions, search and category counts.
5. Run the [Verification Matrix](VERIFICATION_MATRIX.md) in an actual editor/browser where possible. Never mark tests passed based on source review alone.
6. Merge a **documentation-only PR** after static QA.

## Media replacement

See [Media Inventory](MEDIA_INVENTORY.md) and `assets/media-slots.json` for slot type, reader-facing caption, final filename and explicit capture instructions. Keep the normal caption when replacing a placeholder; capture guidance is a second editorial line beneath it. Use screenshots/GIFs from the real plugin.

## Publishing

For GitHub Pages, configure **Settings → Pages → Deploy from a branch → main → /docs** after merge if not already configured. Expected URL: `https://mippi-the-dork.github.io/Stem/`. Verify the live site independently; committing documentation files does not prove Pages is enabled.

## Version accuracy

The documented baseline is Stem v1.0.2. If later releases change settings, visible behavior, supported engines or integration boundaries, update both Design and Technical pages. Prefer historical commit/tag code links for version-specific claims rather than the evolving `main` branch.
