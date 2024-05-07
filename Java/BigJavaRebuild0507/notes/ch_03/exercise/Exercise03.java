package exercise;
public class Exercise03{
    public static void e0301(){
        Counter c = new Counter();              
    
        for (int i=0; i<5; i++){
            System.out.println(c.getValue());
            c.click();
        }

        for (int i=0; i<7; i++){
            c.undo();
            System.out.println(c.getValue());
        }
    }

    public static void e0302(){
        Counter c = new Counter();
        c.setLimit(5);
        for (int i=0; i<10; i++){
            c.click();
            System.out.println(c.getValue());
        }        
        c.setLimit(10);
        for (int i=0; i<10; i++){
            c.click();
            System.out.println(c.getValue());
        }        
        c.setLimit(3);
        System.out.println(c.getValue());
    }

    public static void e0303(){
        Circuit c = new Circuit();

        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleFirstSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleFirstSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleSecondSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleSecondSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleFirstSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleSecondSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleFirstSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();

        c.toggleSecondSwitch();
        System.out.println(c.getFirstSwitchState());
        System.out.println(c.getSecondSwitchState());
        System.out.println(c.getLampState());
        System.out.println();
        
    }

    public static void e0306(){
        BankAccount b = new BankAccount();
        b.deposit(1000);
        b.withdraw(500);
        b.withdraw(400);
        System.out.println(b.getBalance());
    }

    public static void e0307(){
        BankAccount b = new BankAccount(1000);
        b.addInterest(10);
        System.out.println(b.getBalance());
    }

    public static void e0308(){
        SavingsAccount s = new SavingsAccount(1000, 10);
        s.addInterest();
        System.out.println(s.getBalance());
    }

    public static void e0309(){
        CashRegister c = new CashRegister();
        c.recordPurchase(100);
        c.recordPurchase(300);
        c.recordPurchase(500);
        c.receivePayment(1000);

        c.printReceipt();
        System.out.println(c.giveChange());
    }

    public static void e0310(){
        CashRegister c = new CashRegister();
        c.recordPurchase(100);
        c.recordPurchase(300);
        c.recordPurchase(500);
        c.receivePayment(1000);
        c.giveChange();

        c.recordPurchase(1);
        c.recordPurchase(2);
        c.recordPurchase(3);
        c.receivePayment(10);
        c.giveChange();

        //c.printReceipt();
        c.getSalesTotal();
    }

    public static void e0311(){
        Employee harry = new Employee("Hacker, Harry", 50000);
        System.out.println(harry.getSalary());
        harry.raiseSalary(10);
        System.out.println(harry.getSalary());
    }

    public static void e0312(){
        Car myHybrid = new Car(50); // 50 miles per gallon
        myHybrid.addGas(20); // Tank 20 gallons
        myHybrid.drive(100); // Drive 100 miles 
        System.out.println(myHybrid.getGasInTank());
    }

    public static void e0314(){
        Letter l = new Letter("Mary", "John");
        l.addLine("I am sorry we must part.");
        l.addLine("I wish you all the best.");
        System.out.println(l.getText());
    }

    public static void p0301(){
        CashRegister c = new CashRegister();
        c.recordPurchase(100);
        c.recordPurchase(300);
        c.recordPurchase(500);
        c.receivePayment(1000);
        c.giveChange();

        System.out.println(c.getItemCount());

        c.recordPurchase(1);
        c.recordPurchase(2);
        c.recordPurchase(3);
        c.receivePayment(10);
        c.giveChange();

        //c.printReceipt();
        System.out.println(c.getItemCount());
        
    }

    public static void main(String[] args){ 
        p0301();
    }
}