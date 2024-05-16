package ch_09.objects.Question;

import java.util.Scanner;

public class Test {
    public static void questionTest(){
        Question q = new Question();
        q.setText("Who was the inventor of Java?");
        q.setAnswer("James Gosling");

        presentQuestion(q);
    }

    public static void choiceQuestionTest(){
        ChoiceQuestion first = new ChoiceQuestion();
        first.setText("What was the original name of the Java language?");
        first.addChoice("*7", false);
        first.addChoice("Duke", false);
        first.addChoice("Oak", true);
        first.addChoice("Gosling", false);

        ChoiceQuestion second = new ChoiceQuestion();
        second.setText("In which country was the inventor of Java born?");
        second.addChoice("Australia", false);
        second.addChoice("Canada", true);
        second.addChoice("Denmark", false);
        second.addChoice("United States", false);

        presentQuestion(first);
        presentQuestion(second);
    }
    

    // Polymorphism
    public static void presentQuestion(Question q){
        q.display();
        System.out.print("Your answer : ");
        Scanner in = new Scanner(System.in);
        String response = in.nextLine();
        System.out.println(q.checkAnswer(response));
    }


    public static void main(String[] args){
        questionTest();
        // choiceQuestionTest();
    }
}
