package Java.BigJava.ch_05.sub_01;

import java.util.Scanner;

public class ElevatorSimulation{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Floor : ");
        int floor = in.nextInt();

        int actualFloor;
        if (floor > 13){
            actualFloor = floor-1;
        } else {
            actualFloor = floor;
        }

        System.out.println("The elevator will travel to the actual floor " + actualFloor);
    }
}