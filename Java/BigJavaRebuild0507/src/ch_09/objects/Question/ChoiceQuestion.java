package ch_09.objects.Question;

import java.util.ArrayList;

public class ChoiceQuestion extends Question {
    private int CHOICECNT = 1;

    public ChoiceQuestion(){}

    public int sizeOfChoices(){
        return this.CHOICECNT;
    }

    // Newly added method
    public void addChoice(String choice, boolean correct) {        
        this.addText("\n" + this.sizeOfChoices() + ". " + choice);

        if (correct){
            this.setChoiceAnswer(Integer.toString(this.sizeOfChoices()));
        }

        this.CHOICECNT++;
    }

    public void setChoiceAnswer(String choiceAnswer){
        this.setAnswer(choiceAnswer);
    }
}
