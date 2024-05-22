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

    public void addText(String addingText){
        this.text += addingText;
    }

    public String getText(){
        return this.text;
    }

    public void setAnswer(String correctResponse){
        this.answer = correctResponse;
    }

    public String getAnswer(){
        return this.answer;
    }

    public boolean checkAnswer(String response){
        String answerCapitalized = this.answer.toUpperCase();
        return answerCapitalized.equals(response.toUpperCase());
    }

    public void display(){
        System.out.println(this.text);
    }

    public String toString(){
        String result = getClass().getName() + "\n[Question]\n";
        result += this.text;
        return result;
    }
}
