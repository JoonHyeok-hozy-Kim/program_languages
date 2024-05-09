package ch_08.e0809;

import java.util.ArrayList;
import java.util.Scanner;

public class Student {
    private String name;
    private ArrayList<Double> scores = new ArrayList<>();

    public Student(String name){
        this.name = name;
        // this.getScores();
    }

    public void getScores(){
        Scanner in = new Scanner(System.in);
        while (true){
            System.out.print("Enter " + this.name + "'s score : ");
            if (!in.hasNextDouble()) break;
            this.scores.add(in.nextDouble());
        }
    }

    public String showInfo(){
        String result = this.name + " : ";
        for (int i=0; i<this.scores.size(); i++){
            result += scores.get(i);
            if (i < this.scores.size()-1) result += ", ";
        }
        return result;
    }
}
