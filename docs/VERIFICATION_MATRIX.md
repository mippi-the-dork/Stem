# Stem Verification Matrix

**Target:** Stem v1.0.2 · UE 5.8.x · Win64 Editor.  
**Status:** These are reproducible proposed checks; **not performed during this documentation task**. The repository README's previous UE 5.8.2 manual tests are a separate historical claim.

## Record the environment

Document the exact Unreal Engine build, Stem commit/release, project template, installed Outliner-related plugins, display scaling, theme, test date, screenshots and Output Log.

## Unreal Editor functionality

| ID | Scenario | Expected behavior | Status |
| --- | --- | --- | --- |
| STEM-01 | Enable Stem in a clean UE 5.8 Editor and open standard World Outliner | Neutral hierarchy guides appear on expanded native rows | Not run |
| STEM-02 | Expand/collapse nested folders and attached Actors | Guide segments track displayed rows; native arrows work | Not run |
| STEM-03 | Select a deeply nested Actor | Visible ancestor path brightens, selection unchanged | Not run |
| STEM-04 | Select descendants from two branches | Both paths highlighted; shared rails not cumulatively brighter | Not run |
| STEM-05 | Hover unselected row while another selected | Hover path appears/disappears without changing selection | Not run |
| STEM-06 | Hover where selected/hovered paths overlap | Stronger configured brightness wins | Not run |
| STEM-07 | Disable Show Hierarchy Guides | Stem connector lines disappear, native expansion remains | Not run |
| STEM-08 | Change Guide Brightness 0–1 and Thickness 1–4 | Paint opacity and stroke width change without breaking expansion icon | Not run |
| STEM-09 | Adjust Row Height 26.5 → 40 | Open Outliner refreshes; labels, icons and guides align | Not run |
| STEM-10 | Enter height below native minimum | Effective height does not become smaller than native minimum | Not run |
| STEM-11 | Toggle selected/hovered highlighting independently | Correct path contribution enabled/disabled | Not run |
| STEM-12 | Apply search filter/collapse to current branch | No drawn hidden path; visible segments correct | Not run |
| STEM-13 | Inspect pinned ancestor duplicate and custom Outliner picker | Document supported versus unsupported row decoration | Not run |
| STEM-14 | Close/reopen Outliner after enabling Stem | New native rows receive guides | Not run |
| STEM-15 | Quit/restart editor with changed settings | Config values persist, levels remain unmodified | Not run |
| STEM-16 | Close plugin/editor with active guide widgets | No stale delegate/widget crash or unsafe expander replacement | Not run |
| STEM-17 | Stress large expanded Outliner, repeated selection and hover | Acceptable responsiveness; no whole-world path enumeration | Not run |
| STEM-18 | Combine Stem with another label decorator | Native labels and existing decorators remain usable | Not run |

## Documentation website

| ID | Scenario | Expected behavior | Status |
| --- | --- | --- | --- |
| DOC-01 | Navigate all five categories and 34 paired pages | Links, breadcrumbs, Design/Technical switching work | Static checks planned |
| DOC-02 | Search a title and content-only term | Title results immediate, body indexing returns excerpts | Not run |
| DOC-03 | Browser reload/history and deep `?page=` link | Correct article and navigation selection | Not run |
| DOC-04 | Desktop, tablet and 320–400px widths | Sidebar, images, TOC and tables fit without breaking | Not run |
| DOC-05 | Original hero, path GIF, row-height images and settings screenshot | All media load within article width | Not run |
| DOC-06 | New image/GIF placeholders and caption instructions | Type, caption and production instructions match the asset inventory | Static review planned |
| DOC-07 | Keyboard search, tab order, focus, contrast | Site is navigable without a mouse | Not run |
| DOC-08 | Open code source and roadmap links | Correct Stem repository destination | Not run |

## Reporting outcomes

Record **Passed**, **Failed**, **Blocked** or **Not applicable** only after executing the case. Include the exact environment, reproduction steps and linked evidence. Merely reading the source is not a passed Unreal test.

The native Unreal Automation Framework should be used for repeatable tests where implemented; this matrix does not imply such tests currently exist.

[Documentation Audit](DOCUMENTATION_AUDIT.md)
