package ch_10.objects.Measurer;

import java.awt.Rectangle;

public class AverageTest {
    public static void main(String[] args){
        Measurer m = new AreaMeasurer();
        Rectangle[] r = new Rectangle[5];

        for (int i=0; i<5; i++){
            r[i] = new Rectangle(0, 0, 10+5*i, 20+5*i);
        }

        double averageArea = Data.average(r, m);

        System.out.println(averageArea);
    }
}
