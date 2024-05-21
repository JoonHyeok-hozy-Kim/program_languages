package ch_09.objects.Question;

public class FillInQuestion extends Question {
    public FillInQuestion(){}

    public void display(){
        System.out.print(this.getText() + " ");
        String surroundedAnswer = "______";
        System.out.print(surroundedAnswer);
    }
}
