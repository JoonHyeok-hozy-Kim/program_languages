package exercise;

import java.util.Scanner;

public class DataSet05 {
    private double sum=0;
    private double smallest;
    private double largest;
    private double cnt=0;

    public DataSet05(){
        Scanner in = new Scanner(System.in);
        boolean exit = false;
        double curr;
        while (!exit){
            if (cnt == 0){
                System.out.print("Please enter a number: ");
            } else {
                System.out.print("Enter a number. If you want to exit, enter e: ");
            }
            if (in.hasNextDouble()){
                add(in.nextDouble());
            } else {
                exit = true;
            }
        }

        System.out.println("average " + getAverage());
        System.out.println("smallest " + getSmallest());
        System.out.println("largest " + getLargest());
        System.out.println("range " + getRange());
    }

    public void add(double value){
        if (cnt == 0) {
            smallest = value;
            largest = value;
        } else {
            smallest = Math.min(smallest, value);
            largest = Math.max(largest, value);
        }
        sum += value;
        cnt++;
    }

    public double getAverage(){
        if (cnt == 0){
            return 0;
        }
        return sum / cnt;
    }
    
    public double getSmallest(){
        if (cnt == 0){
            return 0;
        }
        return smallest;
    }
    
    public double getLargest(){
        if (cnt == 0){
            return 0;
        }
        return largest;
    }
    
    public double getRange(){
        if (cnt == 0){
            return 0;
        }
        return largest-smallest;
    }
}
