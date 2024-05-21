package ch_09.objects.Question;

import java.util.ArrayList;

public class ChoiceQuestion extends Question {
    private ArrayList<String> choices;

    public ChoiceQuestion(){
        this.choices = new ArrayList<>();
    }

    // Newly added method
    public void addChoice(String choice, boolean correct) {
        this._addCoice(choice);

        if (correct){
            this._setAnswer();
        }
    }

    public void _addCoice(String choice){
        System.out.println(this.getClass().getName() + "_addCoice");
        this.choices.add(choice);
    }

    public void _setAnswer(){
        // System.out.println(this.getClass().getName() + "_setAnswer");
        String choiceString = "" + this.choices.size();
        this.setAnswer(choiceString);
    }

    // Overridden method
    public void display(){
        super.display();
        
        for (int i=0; i<this.choices.size(); i++){
            System.out.println((i+1) + ": " + this.choices.get(i));
        }
    }
}
