package ch_10.exercises.ESeries;

import ch_10.objects.Measurable.Measurable;

public class Quiz implements Measurable {
    private double score;
    private String grade;

    public Quiz(double score, String grade){
        this.score = score;
        this.grade = grade;
    }

    public String toString(){
        return "Score : " + this.score + " / Grade : " + grade;
    }

    public double getMeasure(){
        return this.score;
    }
}
