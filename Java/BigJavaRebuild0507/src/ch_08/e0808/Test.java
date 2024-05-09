package ch_08.e0808;

import java.util.ArrayList;

public class Test {
    public static void main(String[] args){
        // ArrayList<Integer> N = ScoreAnalyzer.readIntegerInputs();
        // System.out.println(N);
        
        ScoreAnalyzer.display(ScoreAnalyzer.createHashMap(ScoreAnalyzer.readNameInputs()));
    }
}
