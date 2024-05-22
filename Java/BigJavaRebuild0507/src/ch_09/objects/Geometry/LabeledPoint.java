package ch_09.objects.Geometry;

import java.awt.Point;

public class LabeledPoint {
    private Point p;
    private String label;

    public LabeledPoint(int x, int y, String label){
        this.p = new Point(x, y);
        this.label = label;
    }

    public String toString(){
        String result = this.p.toString();
        result += ", Label " + this.label;
        return result;
    }
}
