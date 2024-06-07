[Back to Big Java main](../../../main.md)

# 10.8 Building Applicationis with Buttons
- Objective)
  - Learn how to structure a graphical application that contains buttons.
- Full implementation
  - [InvestmentViewer2](../../../src/ch_10/objects/ButtonClick/InvestmentViewer2.java)
- Components
  - Button
    ```java
    JButton button = new JButton("Add Interest");
    ```
    - A button with its label, "Add Interest."
  - Label
    - A user-interface component that displays a message,
    ```java
    JLabel label = new JLabel("Balance: " + account.getBalance());
    ```
  - Panel
    - a container for other user-interface components
    - Why needed?)
      - If we add both button and label on the frame, they will be placed on top of each other.
      - Tus, we should put them into a panel and then add the panel to the frame.
    ```java
    JPanel panel = new JPanel();
    panel.add(button);
    panel.add(label);

    frame.add(panel);
    ```
- Implementing the `ActionListener` interface.
  - where `actionPerformed` method will be provided.
    ```java
    class AddInterestListener implements ActionListener{
        public void actionPerformed(ActionEvent event){
            double interest = account.getBalance() * INTEREST_RATE / 100;
            account.deposit(interest);
            label.setText("Balance: " + account.getBalance());
        }
    }
    ```
    - Here, the `actionPerformed` method manipulates the `account` and `label` variable.
    - They are local variables of the `main` method of the investment viewer program, not instance variables of the `AddInterestListener` class.
    - Thus, the `account` and `label` variables need to be declared as `final` so that the actionPerformed method can access them.
        ```java
        public static void main(String[] args){ 
            JButton button = new JButton("Add Interest");
            final BankAccount account = new BankAccount(INITIAL_BALANCE);
            final JLabel label = new JLabel("balance: " + account.getBalance());

            class AddInterestListener implements ActionListener{
                public void actionPerformed(ActionEvent event){
                    double interest = account.getBalance() * INTEREST_RATE / 100;
                    account.deposit(interest);
                    label.setText("balance: " + account.getBalance());
                } 
            }

            ActionListener listener = new AddInterestListener();
            button.addActionListener(listener);
        }
        ```


<br>

[Back to Big Java main](../../../main.md)