package ch_10.objects.ButtonClick;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JFrame;

import ch_09.objects.BankAccount.BankAccount;

public class InvestmentViewer {
    private static final int FRAME_WIDTH = 100;
    private static final int FRAME_HEIGHT = 60;
    
    private static final double INTEREST_RATE = 10;
    private static final double INITIAL_BALANCE = 1000;

    public static void main(String[] args){
        JFrame frame = new JFrame();
        JButton button = new JButton("Add interest!");
        frame.add(button);

        final BankAccount account = new BankAccount(INITIAL_BALANCE);
    
        class AddInterestListener implements ActionListener{
            public void actionPerformed(ActionEvent event){
                double interest = account.getBalance() * INTEREST_RATE / 100;
                account.deposit(interest);
                System.out.println("Current Balance : " + account.getBalance());
            }
        }
    
        ActionListener listener = new AddInterestListener();
        button.addActionListener(listener);

        frame.setSize(FRAME_WIDTH, FRAME_HEIGHT);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
