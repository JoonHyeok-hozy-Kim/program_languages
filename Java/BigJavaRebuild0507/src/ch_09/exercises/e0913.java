package ch_09.exercises;

import ch_09.objects.Geometry.BetterRectangle;

public class e0913 {
    public static void main(String[] args){
        BetterRectangle b = new BetterRectangle(0, 0, 4, 5);
        System.out.println(b.getPerimeter());
        System.out.println(b.getArea());
    }
}
