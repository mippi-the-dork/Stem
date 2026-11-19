# Path Highlighting

Selected and hovered rows brighten their **displayed ancestor connector paths** without creating a new selection system. Shared segments use the strongest configured brightness rather than stacking visual intensity.

## Topics

| Topic | What you'll learn | Design | Technical |
| --- | --- | --- | --- |
| **Selected Path Highlighting** | Selection makes the connector path through visible ancestors brighter without moving or changing the selected Actor. | [Design](selected/DESIGN.md) | [Technical](selected/TECHNICAL.md) |
| **Hovered Path Highlighting** | Hovering a row temporarily shows its visible ancestor path while leaving Unreal's current selection intact. | [Design](hovered/DESIGN.md) | [Technical](hovered/TECHNICAL.md) |
| **Multiple Selection and Combined Paths** | Several selected rows and a separate hovered row can illuminate overlapping hierarchy segments without stacking their brightness. | [Design](combined/DESIGN.md) | [Technical](combined/TECHNICAL.md) |
