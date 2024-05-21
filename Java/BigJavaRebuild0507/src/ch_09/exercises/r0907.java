package ch_09.exercises;
import ch_09.objects.BankAccount.BankAccount;
import ch_09.objects.BankAccount.SavingsAccount;

public class r0907 {
    public static void main(String[] args){
        BankAccount x = new BankAccount();  // superclass
        SavingsAccount y = new SavingsAccount(); // subclass

        x = y;
        // y = new BankAccount();
        // y = x;
        x = new SavingsAccount();
    }
}
