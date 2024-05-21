package ch_09.objects.BankAccount;

public class SavingsAccount extends BankAccount{
    private double interestRate;
    private double minBalance;

    public SavingsAccount(){

    }

    public void setInterestRate(double rate){
        this.interestRate = rate;
    }

    public void withdraw(double amount){
        super.withdraw(amount);
        double balance = this.getBalance();
        this.minBalance = Math.min(minBalance, balance);
    }

    public void monthEnd(){
        double interest = this.minBalance * this.interestRate;
        this.deposit(interest);
        this.minBalance = this.getBalance();
    }
}