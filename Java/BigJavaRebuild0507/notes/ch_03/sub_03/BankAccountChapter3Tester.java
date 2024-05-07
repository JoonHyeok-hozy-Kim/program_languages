package sub_03;

public class BankAccountChapter3Tester {
    public static void main(String[] args){
        BankAccountChapter3 bc = new BankAccountChapter3();
        double currBalance = bc.getBalance();
        System.out.println(currBalance);

        bc.deposit(1000);
        System.out.println(bc.getBalance());

        bc.withdraw(500);
        System.out.println(bc.getBalance());
    }

}
