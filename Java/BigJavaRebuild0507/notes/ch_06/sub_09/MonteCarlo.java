package sub_09;

import java.util.Random;

public class MonteCarlo {
    public static void main(String[] aStrings){
        final int TRIES = 100000;
        Random generator = new Random();

        int hits = 0;
        for (int i=0; i<TRIES; i++){
            double r = generator.nextDouble();  // [0, 1]
            double x = 2 * r - 1;
            r = generator.nextDouble();
            double y = 2 * r - 1;

            if (x*x + y*y <= 1){
                hits++;
            }
        }

        System.out.printf("%.3f", (double)4*hits/TRIES);
    }
}
