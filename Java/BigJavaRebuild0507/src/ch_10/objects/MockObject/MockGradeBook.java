package ch_10.objects.MockObject;

import java.util.ArrayList;

public class MockGradeBook implements IGradeBook {
    private ArrayList<Double> scores;

    public MockGradeBook(){
        scores = new ArrayList<>();
    }

    public void addScore(int studentId, double score){
        // Ignore the studentId parameter!
        scores.add(score);
    }

    public double getAverageScore(int studentId){
        double sum = 0;
        for (double x: scores){
            sum += x;
        }
        return sum / scores.size();
    }

    public void save(String filename){

    }
}
