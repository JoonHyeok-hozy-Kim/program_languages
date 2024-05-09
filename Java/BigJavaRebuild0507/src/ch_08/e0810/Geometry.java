package ch_08.e0810;

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
        if (p.y == q.y) return 0;
        
    }

    public static double slope(Point2D.Double p, Point2D.Double q){

    }
}
