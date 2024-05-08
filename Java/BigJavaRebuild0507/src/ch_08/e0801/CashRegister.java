package ch_08.e0801;

import java.util.HashMap;

public class CashRegister {
    private HashMap<Coin, Integer> coinStock = new HashMap<>();
    private double balance;
    private double purchase;

    public CashRegister(){
        this.balance = 0;
        this.purchase = 0;
    }

    public void recordPurchase(double amount){
        this.purchase += amount;
    }

    public void receivePayment(int coinCount, Coin coinType){
        if (!coinStock.containsKey(coinType)) coinStock.put(coinType, 0);
        coinStock.replace(coinType, coinStock.get(coinType) + coinCount);
        this.balance += coinCount * coinType.getValue();
    }

    public int giveChange(Coin coinType){
        return (int) (this.purchase / coinType.getValue());
    }

    public String currentCoinsString(){
        String result = "\n";
        for (Coin currCoin: coinStock.keySet()){
            result += currCoin.getName();
            result += " : ";
            result += Integer.toString(coinStock.get(currCoin));
            result += "\n";
        }
        result += "\n";
        return result;
    }
}
