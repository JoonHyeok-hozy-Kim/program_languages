package ch_10.exercises.ESeries;

import java.util.Random;

public class ESerise {
    public static void e1001(){
        Quiz[] quizzes = new Quiz[5];
        for (int i=0; i<5; i++){
            quizzes[i] = new Quiz(4.3-0.3*i, Character.toString('A'+i));
            System.out.println(quizzes[i].toString());
        }
        double average = ch_10.objects.Measurable.Data.average(quizzes);
        System.out.println(average);
        
        Quiz max_quiz = (Quiz) ch_10.objects.Measurable.Data.max(quizzes);
        System.out.println(max_quiz.toString());
    }

    public static void e1002(){
        Person[] people = new Person[5];
        Random r = new Random();
        for (int i=0; i<5; i++){
            people[i] = new Person(Character.toString('A'+2*i), r.nextInt(160, 180));
            System.out.println(people[i].toString());
        }

        System.out.println(ch_10.objects.Measurable.Data.average(people));
        System.out.println(ch_10.objects.Measurable.Data.max(people).toString());
    }

    public static void main(String[] args){
        e1002();
    }
}
