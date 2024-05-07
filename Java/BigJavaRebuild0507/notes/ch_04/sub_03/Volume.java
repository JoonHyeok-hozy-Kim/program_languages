package Java.BigJava.ch_04.sub_03;

import java.util.Scanner;

public class Volume {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        System.out.print("Please enter the price for a six-pack : ");
        double packPrice = in.nextDouble();

        System.out.print("Please enter the price for a two-liter bottle : ");
        double bottlePrice = in.nextDouble();

        final double CANS_PER_PACK = 6;  
        final double CAN_VOLUME = 0.355;    // 12oz = 0.3551
        final double BOTTLE_VOLUME = 2;

        double packPricePerLiter = packPrice / (CANS_PER_PACK * CAN_VOLUME);
        double bottlePricePerLiter = bottlePrice / BOTTLE_VOLUME;

        System.out.printf("Pack price per liter : %8.2f", packPricePerLiter);
        System.out.println();

        System.out.printf("Bottle price per liter : %8.2f", bottlePricePerLiter);
        System.out.println();
    }
}
