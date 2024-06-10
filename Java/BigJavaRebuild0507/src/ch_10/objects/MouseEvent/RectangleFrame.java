package ch_10.objects.MouseEvent;

import javax.swing.JFrame;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import ch_10.objects.TimerEvent.RectangleComponent;

public class RectangleFrame extends JFrame {
    private static final int FRAME_WIDTH = 1000;
    private static final int FRAME_HEIGHT = 1000;

    // Reusing the component from the TimerEvent package.
    private RectangleComponent scene;

    class MousePressListener implements MouseListener{
        public void mousePressed(MouseEvent event){
            int x = event.getX();
            int y = event.getY();
            scene.moveRectangleBy(x, y);
        }

        public void mouseReleased(MouseEvent event) {}
        public void mouseClicked(MouseEvent event) {}
        public void mouseEntered(MouseEvent event) {}
        public void mouseExited(MouseEvent event) {}
    }

    public RectangleFrame(){
        scene = new RectangleComponent();
        add(scene);

        MouseListener listener = new MousePressListener();
        scene.addMouseListener(listener);   // Adding MouseListener to the component!

        setSize(FRAME_WIDTH, FRAME_HEIGHT);
    }
}
