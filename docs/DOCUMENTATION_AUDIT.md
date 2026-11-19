# Stem Documentation Audit

**Baseline:** Stem v1.0.2.  
**Reviewed sources:** `README.md`, `Doc/Sources.md`, `Stem.uplugin`, `StemModule.cpp`, `StemGuideArrow.h`, `StemSettings.h/.cpp`.  
**Status:** Source/editorial audit. It does **not** replace hands-on Unreal Engine or browser QA.

## Assessment

The current site documents the public plugin by behavior and implementation, rather than copying the README into both page types. It has **five sections, 17 Design/Technical topic pairs**, source links and an explicit record of known limitations.

The highest-value evidence already in the repository is the hero image, path-highlighting GIF, settings screenshot and two row-height comparison screenshots. The site reuses those originals instead of substituting fabricated UI.

## Gaps and next actions

| Priority | Gap | Resolution/next step | Status |
| --- | --- | --- | --- |
| P0 | Distinguish Designer workflow from C++ implementation | Separate Design and Technical pages for each of 17 topics | Authored, review in browser |
| P0 | Avoid overstating support for custom Outliners or Unreal versions | Name standard Actor Browser scope, UE 5.8.x targeting, and manual UE 5.8.2 verification | Documented |
| P0 | Make setting values discoverable | Table of all eight settings, defaults, ranges and conditions | Documented |
| P1 | Teach without relying only on text | Include original media and typed placeholders with exact instructions | Authored; new capture pending |
| P1 | Support real troubleshooting | Symptom-based support Design and diagnosis-oriented Technical guidance | Documented; manual QA pending |
| P1 | Actual versioned UE test evidence | Execute [Verification Matrix](VERIFICATION_MATRIX.md) and record logs, versions and observations | Not run in this pass |
| P1 | Website/mobile/accessibility QA | Test navigation, body search, images, table width, keyboard and small screens | Not run in this pass |
| P2 | Historical roadmap | Current v1.0.2 is grounded; prior version-specific feature history not established | No chronology invented |
| P2 | Version-pinned source links | Prefer release tags/commits over `main` links once historical versions are maintained | Still desirable |

## Visual documentation

The typed media slots list each final asset's intended type, reader-facing caption, exact screenshot/GIF content and replacement filename. Replacements should depict the **actual running Stem plugin**. Source diagrams should be technically accurate and labeled as diagrams, not mistaken for screenshots.

[Media Inventory](MEDIA_INVENTORY.md)

## Validation boundaries

The repository reports manual Unreal Engine **5.8.2** testing of hierarchy guides, row height, appearance controls, hover/selection highlighting and standard Outliner operation. That report is distinct from running this new documentation checklist. Live browser verification and actual GitHub Pages publication still require explicit confirmation.

[Verification Matrix](VERIFICATION_MATRIX.md) · [Documentation Home](README.md)
