package ch_09.objects.BankAccount;

public class BasicAccount extends BankAccount {
    public BasicAccount(){}

    public void withdraw(double amount){
        if (this.getBalance() < amount) this.overdraft();
        super.withdraw(amount);
    }

    public void overdraft(){
        final double OVERDRAFT_PENALTY = 30;
        super.withdraw(OVERDRAFT_PENALTY);
    }
}
