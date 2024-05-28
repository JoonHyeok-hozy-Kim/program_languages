package ch_10.objects.Measurer;
import java.awt.Rectangle;

public class AreaMeasurer implements Measurer {
    public double measure(Object object){
        Rectangle r = (Rectangle) object;
        return r.getWidth() * r.getHeight();
    }
}
