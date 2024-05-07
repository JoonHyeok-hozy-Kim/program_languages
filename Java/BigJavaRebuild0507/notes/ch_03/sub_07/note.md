[Back to Big Java main](../../../main.md)

# 3.7 The ```this``` Reference
### Concept) Implicit Parameter
- Desc.)
  - When you implement the **method**, you provide a parameter variable for each argument. 
  - But you don’t need to provide **a parameter variable for the object on which the method** is being invoked. 
  - That object is called the **implicit parameter**. 
- cf.)
  - All other parameter variables are called **explicit parameters**.
- e.g.)
  - Recall the [BanckAccountChapter3](../sub_03/BankAccountChapter3.java) class.
  - It had the ```deposit``` method as the following.
    ```java
    public void deposit(double amount){
        balance += amount;
    }
    ```
  - Suppose we instantiated a ```BanckAccountChapter3``` class.
    ```java
    BanckAccountChapter3 momsSavings = new BanckAccountChapter3();
    momsSavings.deposit(500);
    ```
  - When calling the ```deposit``` method, we provide the ```amount``` parameter which is the explicit parameter.
  - However, the ```balance``` parameter is not provided.
    - This is the implicit parameter.
    - The compiler actually automatically puts ```this``` reference to the implicit parameters.
      - i.e.)
        ```java
        public void deposit(double amount){
            this.balance += amount;
        }
        ```

#### Tech.) Calling One Constructor from Another
```java
public class BankAccount{ 
 public BankAccount(double initialBalance)  { 
    balance = initialBalance;
 } 

 public BankAccount()  { 
 this(0);
 } 
 
}
```


<br>

[Back to Big Java main](../../../main.md)