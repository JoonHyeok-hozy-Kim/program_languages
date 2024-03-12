package sub_01;

public class Investment {
    private double balance;
    private double rate;
    private int year;

    public Investment(double aBalance, double aRate){
        this.balance = aBalance;
        this.rate = aRate;
        this.year = 0;
    }

    public void waitForBalance(double targetBalance){
        while (balance < targetBalance){
            year++;
            balance += balance * rate / 100;
        }
    }

    public double getBalance(){
        return balance;
    }

    public int getYears(){
        return year;
    }
}
