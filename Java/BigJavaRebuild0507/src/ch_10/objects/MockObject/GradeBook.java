package ch_10.objects.MockObject;

import java.util.ArrayList;
import java.util.HashMap;

public class GradeBook {
    private HashMap<Integer, ArrayList<Double>> data;

    public GradeBook(){
        this.data = new HashMap<>();
    }

    public void addScore(int studentId, double score) {
        if (! this.data.containsKey(studentId)){
            this.data.put(studentId, new ArrayList<Double>());
        }
        this.data.get(studentId).add(score);
    }

    public double getAverageScore(int studentId) {
        if (! this.data.containsKey(studentId) || this.data.get(studentId).size() == 0){
            return 0;
        }

        double sum = 0;
        ArrayList<Double> scoreList = this.data.get(studentId);
        for (double scr: scoreList){
            sum += scr;
        }
        return sum / scoreList.size();
    }

    public void save(String filename) {
        // Saving!
    }
}
