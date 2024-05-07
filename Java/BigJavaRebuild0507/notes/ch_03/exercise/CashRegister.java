package exercise;

import java.util.ArrayList;

public class CashRegister {
    protected ArrayList<Double> purchaseList = new ArrayList<>();
    protected ArrayList<Double> paymentList = new ArrayList<>();
    protected ArrayList<Double> purchaseListTemp = new ArrayList<>();
    protected ArrayList<Double> paymentListTemp = new ArrayList<>();

    public CashRegister(){    
    }

    public void recordPurchase(double amount){
        purchaseListTemp.add(amount);

    }

    public void receivePayment(double amount){
        paymentListTemp.add(amount);    
    }

    public double giveChange(){
        double change = 0;
        for (int i=0; i<purchaseListTemp.size(); i++){
            change -= purchaseListTemp.get(i);
            purchaseList.add(purchaseListTemp.get(i));
        }
        for (int i=0; i<paymentListTemp.size(); i++){
            change += paymentListTemp.get(i);
            paymentList.add(paymentListTemp.get(i));
        }
        purchaseListTemp.clear();
        paymentListTemp.clear();
        return change;
    }

    private void getTotal(ArrayList<Double> l){
        double amount = 0;
        for (int i=0; i<l.size(); i++){
            amount += l.get(i);
            System.out.print(i+1);
            System.out.print(". ");
            System.out.println(l.get(i));
        }
        System.out.print("Total : ");
        System.out.println(amount);
    }

    public void printReceipt(){
        getTotal(purchaseListTemp);
    }

    public void getSalesTotal(){
        getTotal(purchaseList);
    }

    public void reset(){
        purchaseList.clear();
        //purchaseListTemp.clear();
        paymentList.clear();
        //paymentListTemp.clear();
    }

    public int getItemCount(){
        return this.purchaseList.size();
    }
}
