package ch_09.objects.Question;

import java.util.ArrayList;
import java.util.Arrays;

public class AnyCorrectChoicesQuestion extends ChoiceQuestion {

    public AnyCorrectChoicesQuestion(){}

    public void setChoiceAnswer(String choiceAnswer){
        String prevAnswer = this.getAnswer();
        if (prevAnswer.length() > 0) prevAnswer += " ";
        prevAnswer += choiceAnswer;
        this.setAnswer(prevAnswer);
    }

    public boolean checkAnswer(String response){
        String[] answerArray = this.getAnswer().split(" ");
        for (int i=0; i<answerArray.length; i++){
            if (response.equals(answerArray[i])) return true;
        }
        return false;
    }
}
