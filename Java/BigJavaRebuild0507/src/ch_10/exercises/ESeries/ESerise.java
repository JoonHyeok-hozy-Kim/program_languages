package ch_10.exercises.ESeries;

import java.util.Random;
import java.awt.Rectangle;

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

    public static int fiboTest(int n){
        if (n == 1 || n == 2) return 1;
        return fiboTest(n-2) + fiboTest(n-1);
    }

    public static class AreaMeasurer2 implements ch_10.exercises.Measurer.Measurer{
        public double measure(Object obj){
            Rectangle r = (Rectangle) obj;
            return r.getWidth() * r.getHeight();
        }
    }

    public static void e1008(){
        Rectangle[] R = new Rectangle[5];
        Random r = new Random();
        for (int i=0; i<5; i++){
            R[i] = new Rectangle(r.nextInt(5), r.nextInt(5), r.nextInt(5),r.nextInt(5));
            System.out.println(R[i]);
        }

        System.out.println(ch_10.exercises.Measurer.Data.max(R, new AreaMeasurer2()));
    }

    public static void main(String[] args){
        e1008();
    }
}
