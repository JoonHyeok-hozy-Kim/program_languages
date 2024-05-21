package ch_09.objects.BankAccount;

public class BankAccount {
    private double balance;

    public BankAccount(){
        
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
