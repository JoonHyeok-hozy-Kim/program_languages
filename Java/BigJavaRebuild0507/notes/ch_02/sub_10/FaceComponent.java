import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

import javax.swing.JComponent;

public class FaceComponent extends JComponent {
    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g;

        // Draw an ellipse
        Ellipse2D.Double head = new Ellipse2D.Double(5, 10, 100, 150);
        g2.draw(head);

        // Draw rectangles and color them red
        g2.setColor(Color.GREEN);
        Rectangle eye = new Rectangle(25, 70, 15, 15);
        g2.fill(eye);
        eye.translate(50, 0);
        g2.fill(eye);

        // Draw a line between two points
        Point2D.Double p1 = new Point2D.Double(30, 110);
        Point2D.Double p2 = new Point2D.Double(80, 110);
        Line2D.Double mouth = new Line2D.Double(p1, p2);
        g2.draw(mouth);

        // Draw a text
        g2.setColor(Color.CYAN);
        g2.drawString("Hello, earth!", 5, 175);
    }
}
