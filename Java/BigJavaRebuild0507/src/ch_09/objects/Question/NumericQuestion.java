package ch_09.objects.Question;

public class NumericQuestion extends Question {
    public NumericQuestion(){}

    public boolean checkAnswer(double response){
        double answerDouble = Double.parseDouble(this.getAnswer());
        return Math.abs(answerDouble - response) < 0.01;
    }
    
}
