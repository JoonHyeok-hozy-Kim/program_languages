package ch_08.e0808;

import java.util.ArrayList;
import java.util.Scanner;

public class ScoreAnalyzer {
    public static ArrayList<String> readStringInputs(){
        Scanner in = new Scanner(System.in);
        ArrayList<String> result = new ArrayList<>();
        while (true){
            if (!in.hasNextLine()) break;
            result.add(in.nextLine());
        }
        return result;
    }
    
    public static ArrayList<Double> readDoubleInputs(ArrayList<String> nameList){
        Scanner in = new Scanner(System.in);
        ArrayList<Double> result = new ArrayList<>();
        while (true){
            if (!in.hasNextDouble()) break;
            result.add(in.nextDouble());
        }
        return result;
    }

    public static Double sum(ArrayList<Double> values){
        double result = 0;
        for (double v: values){
            result += v;
        }
        return result;
    }
}
