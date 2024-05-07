[Back to Big Java main](../../main.md)

# 3.2 Specifying the Public Interface of a Class
### Concept) Constructor
- Desc.)
  - In Java, a constructor is very similar to a **method**, with two important differences:
     1. The name of the constructor is always the same as the name of the class.
     2. Constructors have no return type (not even ```void```).
```java
public class BankAccount{
    private instance_variables;

    // Constructors
    public BankAccount(){   // no-argument constructor
        // implementation—filled in later
    }
    public BankAccount(double initialBalance){ 
        //implementation—filled in later
    }

    // Methods
    public void deposit(double amount)    { 
        //implementation—filled in later
    }
    public void withdraw(double amount)    { 
        //implementation—filled in later
    }
    public double getBalance()    { 
        //implementation—filled in later
        return 0;
    }
}
```

<br>

### Concept) Public Interface
- The public constructors and methods of a class form the public interface of the class. 

<br>

### Concept) Commenting
- In Java there is a very useful standard form for **documentation comments**.
  - A program called **javadoc** can automatically generate a neat set of HTML pages that describe them. 
- e.g.)
    ```java
    /**
     Withdraws money from the bank account.
    @param amount the amount to withdraw
    */
    public void withdraw(double amount) { 
        //implementation—filled in later
    }
    /**
     Gets the current balance of the bank account.
    @return the current balance
    */
    public double getBalance() { 
        //implementation—filled in later
    }
    ```

<br>

[Back to Big Java main](../../main.md)