package ch_10.objects.Measurable;

public class BankAccount implements Measurable {
    private double balance;

    public BankAccount(double balance){
        this.balance = balance;
    }

    public double getMeasure(){
        return this.balance;
    }
    
}
