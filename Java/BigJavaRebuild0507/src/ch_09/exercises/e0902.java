package ch_09.exercises;

import ch_09.objects.BankAccount.BasicAccount;

public class e0902 {
    public static void main(String[] args){
        BasicAccount b = new BasicAccount();
        b.deposit(100);
        for (int i=0; i<5; i++){
            b.withdraw(30);
            System.out.println(b.getBalance());
        }
    }
}
