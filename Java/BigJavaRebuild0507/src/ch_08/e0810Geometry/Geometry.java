package ch_08.e0810Geometry;

import java.awt.geom.Point2D;
import java.awt.geom.Ellipse2D;

public class Geometry {
    public static double perimeter(Ellipse2D.Double e){
        double l = Math.max(e.height, e.width);
        double s = Math.min(e.height, e.width);
        return Math.PI * (3 * (s + l) - Math.sqrt((3*s+l)*(s+3*l)));
    }

    public static double area(Ellipse2D.Double e){
        return Math.PI * e.height * e.width;
    }    

    public static double angle(Point2D.Double p, Point2D.Double q){
        return Math.atan(slope(p, q));
    }

    public static double slope(Point2D.Double p, Point2D.Double q){
        if (p.y == q.y) return 0;
        else if (p.x == q.x) return Double.POSITIVE_INFINITY;
        return (q.y - p.y) / (q.x - p.x);
    }

    public static boolean isInside(Point2D.Double p, Ellipse2D.Double e){
        return (Math.pow((p.x - e.x), 2) / e.width + Math.pow((p.y - e.y), 2) / e.height) < 1;
    }

    public static boolean isOnBoundary(Point2D.Double p, Ellipse2D.Double e){
        return (Math.pow((p.x - e.x), 2) / e.width + Math.pow((p.y - e.y), 2) / e.height) == 1;
    }
}
