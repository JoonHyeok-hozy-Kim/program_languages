package ch_08.e0801;

public class Test {
    public static void main(String[] args){
        Coin[] coins = {
            new Coin(0.25, "Quarter"),
            new Coin(0.1, "Dime"),
            new Coin(0.05, "Nickel"),
        };

        CashRegister cr = new CashRegister();
        for (Coin c: coins){
            cr.receivePayment(100, c);
        }

        System.out.println(cr.currentCoinsString());

        cr.recordPurchase(10);
        System.out.println(cr.giveChange(coins[0]));
    }
}
