package ch_09.objects.Question;

public class Question {
    private String text;
    private String answer;

    public Question(){
        this.text = "";
        this.answer = "";
    }

    public void setText(String questionText) {
        this.text = questionText;
    }

    public void setAnswer(String correctResponse){
        this.answer = correctResponse;
    }

    public boolean checkAnswer(String response){
        return this.answer.equals(response);
    }

    public void display(){
        System.out.println(this.text);
    }
}
