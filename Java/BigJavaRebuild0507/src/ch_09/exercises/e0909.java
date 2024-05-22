package ch_09.exercises;

import ch_09.objects.Question.AnyCorrectChoicesQuestion;
import ch_09.objects.Question.ChoiceQuestion;
import ch_09.objects.Question.MultiChoiceQuestion;

public class e0909 {
    public static void ChoiceQuestionTester(ChoiceQuestion c){
        
        c.setText("How are you?");

        c.addChoice("abc", false);
        c.addChoice("def", true);
        c.addChoice("ghi", false);
        c.addChoice("jkl", false);
        c.addChoice("jkl", false);
        
        c.display();
        

        for (int i=0; i<5; i++){
            System.out.println(c.checkAnswer(Integer.toString(i+1)));
        }

    }
    public static void AnyCorrectChoicesQuestionTester(AnyCorrectChoicesQuestion c){
        
        c.setText("How are you?");

        c.addChoice("abc", false);
        c.addChoice("def", true);
        c.addChoice("ghi", false);
        c.addChoice("jkl", true);
        c.addChoice("jkl", false);
        
        c.display();
        

        for (int i=0; i<5; i++){
            System.out.println(c.checkAnswer(Integer.toString(i+1)));
        }

    }
    public static void MultiChoiceQuestionTester(MultiChoiceQuestion c){
        
        c.setText("How are you?");

        c.addChoice("abc", false);
        c.addChoice("def", true);
        c.addChoice("ghi", false);
        c.addChoice("jkl", true);
        c.addChoice("jkl", false);
        
        c.display();
        

        for (int i=0; i<5; i++){
            System.out.println(c.checkAnswer(Integer.toString(i+1)));
        }

        System.out.println(c.checkAnswer("2 4"));
        System.out.println(c.checkAnswer("4 2"));
    }


    public static void main(String[] args){
        ChoiceQuestion c = new ChoiceQuestion();
        AnyCorrectChoicesQuestion ac = new AnyCorrectChoicesQuestion();
        MultiChoiceQuestion mc = new MultiChoiceQuestion();

        // ChoiceQuestionTester(c);
        // ChoiceQuestionTester(ac);
        // AnyCorrectChoicesQuestionTester(ac);

        // ChoiceQuestionTester(mc);
        // AnyCorrectChoicesQuestionTester(mc);
        MultiChoiceQuestionTester(mc);
    }
}
