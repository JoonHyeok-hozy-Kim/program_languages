package ch_09.objects.Question;

import java.util.ArrayList;

public class ChoiceQuestion extends Question {
    private ArrayList<String> choices;

    // Newly added method
    public void addChoices(String choice, boolean correct) {
        this.choices.add(choice);

        if (correct){
            String choiceString = "" + this.choices.size();
            this.setAnswer(choiceString);
        }
    }

    // Overridden method
    public void display(){

    }
}
