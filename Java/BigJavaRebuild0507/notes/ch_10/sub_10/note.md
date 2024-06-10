[Back to Big Java main](../../../main.md)

# 10.10 Mouse Events
- Desc.)
  - Mouse event listener must implement the `MouseListener` interface.
    - `MouseListener` contains five methods.
      ```java
      public interface MouseListener{
        void mousePressed(MouseEvent event);
            // Called when a mouse button has been pressed on a component 
        void mouseReleased(MouseEvent event);
            // Called when a mouse button has been released on a component 
        void mouseClicked(MouseEvent event);
            // Called when the mouse has been clicked on a component 
        void mouseEntered(MouseEvent event);
            // Called when the mouse enters a component 
        void mouseExited(MouseEvent event);
            // Called when the mouse exits a component
      }
      ```
  - Add a mouse listener to a component by calling the `addMouseListener` method.
    - e.g.)   
      ```java
      public class MyMouseListener implements MouseListener{
        // Implement five methods
      }

      MouseListener listener = new MyMouseListener();
      component.addMouseListener(listener);
      ```
- e.g.)
  - 


<br>

[Back to Big Java main](../../../main.md)