package exercise;

public class BankAccount {
    
    // Instance Variable
    protected double balance;

    // Constructors
    public BankAccount(){
        balance = 0;
    }

    public BankAccount(double initialBalance){
        balance = initialBalance;
    }

    // Methods
    public void deposit(double amount){
        balance += amount;
    }

    public void withdraw(double amount){
        balance -= amount;
    }

    public double getBalance(){
        return balance;
    }

    public void addInterest(double rate){
        balance *= 1 + rate/100;
    }
}
