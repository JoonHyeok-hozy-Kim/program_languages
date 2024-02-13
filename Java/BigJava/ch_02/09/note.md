[Back to Big Java main](../../main.md)

# 2.9 Graphical Applications
### Concept) Graphical Applications
- Desc.)
  - Applications that display drawings inside a window. 
  - The drawings are made up of shape objects: rectangles, ellipses, and lines.

## 2.9.1 Frame Windows
### Concept) Frame
- Desc.)
  - A window with a title bar
- Class)
  - ```JFrame```
    - [Usage example](FrameTest.java)

<br>

## 2.9.2 Drawing on a Component
How to make shapes appear inside a frame window.
### Concept) Component
- Desc.)
  - Drawing happens in a **component** object. 
  - In the Swing toolkit, the ```JComponent``` class represents a blank component.
- E.g.)
  - Script

<br>

## 2.9.3 Displaying a Component in a Frame
Combining a [frame](#concept-frame) with a [component](#concept-component).

- How to)
  1. Construct a frame object and configure it.
  2. Construct an object of your component class: ```RectangleComponent component = new RectangleComponent(); ```
  3. Add the component to the frame: ```frame.add(component); ```
  4. Make the frame visible.
- [Script](RectangleViewer.java)

<br>

[Back to Big Java main](../../main.md)