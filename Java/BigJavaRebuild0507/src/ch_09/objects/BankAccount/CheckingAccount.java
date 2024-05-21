package ch_09.objects.BankAccount;

public class CheckingAccount extends BankAccount {
    private int withdrawals;

    public CheckingAccount(){

    }

    public void withdraw(double amount){
        final int FREE_WITHDRAWLS = 3;
        final int WITHDRAWAL_FEE = 1;
        
        if (this.getBalance() < amount){
            if (this.getBalance() < 0) super.withdraw(30);
            else super.withdraw(20);
        }
        super.withdraw(amount);
        this.withdrawals++;
        if (this.withdrawals > FREE_WITHDRAWLS){
            super.withdraw(WITHDRAWAL_FEE);
        }
    }

    public void monthEnd(){
        this.withdrawals = 0;
    }
}
