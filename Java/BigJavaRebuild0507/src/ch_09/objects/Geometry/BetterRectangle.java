package ch_09.objects.Geometry;

import java.awt.Rectangle;

public class BetterRectangle extends Rectangle {
    public BetterRectangle(int x, int y, int width, int height){
        // this.setLocation(x, y);
        // this.setSize(width, height);

        super(x, y, width, height);
    }

    public double getPerimeter(){
        return (this.getWidth() + this.getHeight()) * 2;
    }

    public double getArea(){
        return this.getWidth() * this.getHeight();
    }
}
