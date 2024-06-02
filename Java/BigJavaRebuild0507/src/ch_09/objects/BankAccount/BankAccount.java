package ch_09.objects.BankAccount;

public class BankAccount {
    private double balance;

    public BankAccount(){
        this.balance = 0;
    }

    public BankAccount(double initBalance){
        this.balance = initBalance;
    }
    
    public void deposit(double amount){
        this.balance += amount;
    }

    public void withdraw(double amount){
        this.balance -= amount;
    }

    public void monthEnd(){

    }

    public double getBalance(){
        return this.balance;
    }
}
