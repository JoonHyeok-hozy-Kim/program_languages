package ch_09.exercises;

import ch_09.objects.Question.MultiChoiceQuestion;

public class e0908 {
    public static void main(String[] args){
        MultiChoiceQuestion a = new MultiChoiceQuestion();

        a.setText("dfjoaisfj;sdofijasdf;o???");

        a.addChoice("abc", false);
        a.addChoice("def", true);
        a.addChoice("ghi", false);
        a.addChoice("jkl", false);
        a.addChoice("mno", true);
        a.addChoice("abc", false);
        
        a.display();
        

        for (int i=0; i<6; i++){
            System.out.println(a.checkAnswer(Integer.toString(i+1)));
        }

        System.out.println(a.checkAnswer("2 5"));
        System.out.println(a.checkAnswer("5 2"));

    }
}
