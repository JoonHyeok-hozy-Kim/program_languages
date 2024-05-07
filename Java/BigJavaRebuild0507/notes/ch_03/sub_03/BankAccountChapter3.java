package sub_03;

public class BankAccountChapter3 {
    // Instance Variable
    private double balance;

    // Constructors
    public BankAccountChapter3(){
        balance = 0;
    }

    public BankAccountChapter3(double initialBalance){
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

}
