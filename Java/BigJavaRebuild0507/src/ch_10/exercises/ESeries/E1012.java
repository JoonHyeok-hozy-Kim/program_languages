package ch_10.exercises.ESeries;

import java.awt.Rectangle;
import java.util.Random;

public class E1012 {
    public static class PerimeterMeasurer2 implements ch_10.exercises.Measurer.Measurer{
        public double measure(Object object){
            Rectangle r = (Rectangle) object;
            return (r.getWidth() + r.getHeight()) * 2;
        }
    }

    public static void main(String[] args){
        Random r = new Random();
        Rectangle[] R = new Rectangle[5];
        for (int i=0; i<5; i++){
            R[i] = new Rectangle(r.nextInt(5),r.nextInt(5),r.nextInt(5),r.nextInt(5));
            System.out.println(R[i]);
        }

        System.out.println(ch_10.exercises.Measurer.Data.max(R, new PerimeterMeasurer2()));
    }
}
