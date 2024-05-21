package ch_09.objects.Question;

import java.util.ArrayList;

public class MultiChoiceQuestion extends ChoiceQuestion {
    private ArrayList<String> choices;

    public MultiChoiceQuestion(){
        this.choices = new ArrayList<>();
    }

    public void addChoice(String choice, boolean correct){
        this.choices.add(choice);

        if (correct){

        }
    }


}
