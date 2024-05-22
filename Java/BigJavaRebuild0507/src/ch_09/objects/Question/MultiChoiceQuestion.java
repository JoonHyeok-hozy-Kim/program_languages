package ch_09.objects.Question;

import java.util.ArrayList;
import java.util.Arrays;

public class MultiChoiceQuestion extends AnyCorrectChoicesQuestion {
    public MultiChoiceQuestion(){}

    public boolean checkAnswer(String response){
        String[] answerArray = this.getAnswer().split(" ");
        String[] responseArray = response.split(" ");

        if (answerArray.length != responseArray.length) return false;
        Arrays.sort(answerArray);
        Arrays.sort(responseArray);
        for (int i=0; i<answerArray.length; i++){
            if (! answerArray[i].equals(responseArray[i])) return false;
        }
        return true;
    }

}
