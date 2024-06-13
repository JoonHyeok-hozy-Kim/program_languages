package ch_10.exercises.ESeries;

import java.awt.Rectangle;
import java.util.Random;

public class E1011 {
    public static void main(String[] args){
        class PerimeterMeasurer implements ch_10.exercises.Measurer.Measurer{
            public double measure(Object o){
                Rectangle r = (Rectangle) o;
                return 2 * (r.getWidth() + r.getHeight());
            }
        }

        Random r = new Random();
        Rectangle[] R = new Rectangle[5];
        for (int i=0; i<5; i++){
            R[i] = new Rectangle(r.nextInt(5),r.nextInt(5),r.nextInt(5),r.nextInt(5));
            System.out.println(R[i]);
        }

        System.out.println(ch_10.exercises.Measurer.Data.max(R, new PerimeterMeasurer()));
    }
}
