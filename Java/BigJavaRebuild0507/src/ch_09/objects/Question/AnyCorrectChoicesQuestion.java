package ch_09.objects.Question;

import java.util.ArrayList;

public class AnyCorrectChoicesQuestion extends ChoiceQuestion {
    private ArrayList<String> choices;

    public AnyCorrectChoicesQuestion(){
        this.choices = new ArrayList<>();
    }

    public void _setAnswer(){
        System.out.println(this.getClass().getName() + "_setAnswer");
        String prevAnswer = this.getAnswer();
        prevAnswer += " " + this.choices.size();
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
