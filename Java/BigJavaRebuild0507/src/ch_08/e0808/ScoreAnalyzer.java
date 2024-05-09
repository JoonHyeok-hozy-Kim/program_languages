package ch_08.e0808;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class ScoreAnalyzer {
    public static ArrayList<String> readNameInputs(){
        Scanner in = new Scanner(System.in);
        ArrayList<String> result = new ArrayList<>();
        String tempInput;
        String escaper = "x";
        while (true){
            System.out.print("Enter the name (Enter " + escaper + " to exit): ");
            tempInput = in.nextLine();
            if (tempInput.equals(escaper)) break;
            result.add(tempInput);
        }
        return result;
    }
    
    public static ArrayList<Double> readScoreInputs(String name){
        Scanner in = new Scanner(System.in);
        ArrayList<Double> result = new ArrayList<>();
        while (true){
            System.out.print("Enter " + name + "'s score : ");
            if (!in.hasNextDouble()) break;
            result.add(in.nextDouble());
        }
        return result;
    }

    public static HashMap<String, ArrayList<Double>> createHashMap(ArrayList<String> namesList){
        HashMap<String, ArrayList<Double>> result = new HashMap<>();
        for (String name: namesList){
            result.put(name, readScoreInputs(name));
        }
        return result;
    }

    public static void display(HashMap<String, ArrayList<Double>> h){
        for (String name: h.keySet()){
            System.out.print(name + " : ");
            for (Double score: h.get(name)){
                System.out.print(score + ", ");
            }
            System.out.println();
        }
    }
}
