package ch_09.exercises;

import ch_09.objects.Question.Question;

public class e0906 {
    public static void main(String[] ars){
        Question q = new Question();
        q.setAnswer("James Gosling");
        System.out.println(q.checkAnswer("JAMES gosling"));
    }
}
