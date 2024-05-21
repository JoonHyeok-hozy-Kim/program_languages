package ch_09.exercises;

import ch_09.objects.BankAccount.BasicAccount;
import ch_09.objects.BankAccount.CheckingAccount;

public class e0903 {
    public static void main(String[] args){
        CheckingAccount b = new CheckingAccount();
        b.deposit(10);
        for (int i=0; i<5; i++){
            b.withdraw(10);
            System.out.println(b.getBalance());
        }
    }
}
