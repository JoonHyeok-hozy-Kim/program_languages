package exercise;

public class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(double initialBalance, double interestRate){
        this.balance = initialBalance;
        this.interestRate = interestRate;
    }

    public void addInterest(){
        addInterest(interestRate);
    }
}
