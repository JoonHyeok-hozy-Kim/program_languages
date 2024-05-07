[Back to Big Java main](../../../main.md)

# 8.4 Static Variables and Methods
### Concept) Static Variable
- Desc.)
  - A value properly belongs to a **class**, not to any object of the class. 
- e.g.) Bank Account ID
  ```java
  public class BankAccount{
    private double balance;
    private int accountID;
    private static int lastAssignedID = 1000;   // Static variable

    public BankAccount(){
        lastAssignedID++;   // Incremented among every instance
        accountNumber = lastAssignedID;
    }
  }
  ```
- Prop.)
  - Static **variables** should always be declared as ```private``` to ensure that methods of other classes do not change their values. 
    - However, static **constants** may be either ```private``` or ```public```. 
      - e.g.)
        ```java
        public class BankAccount{
            public static final double OVERDRAFT_FEE = 29.95;   // Public static
        }
        ```
      - Methods from any class can refer to such a constant as ```BankAccount.OVERDRAFT_FEE```. 
  - Static variables should be initialized either by the default value or by using a static block.
    - Default Value Case
      ```java
      public class BankAccount{
          public static final double OVERDRAFT_FEE = 29.95;   // The default value of 29.95.
      }
      ```
    - Static Block Case
      ```java
      public class BankAccount{
          public static final double OVERDRAFT_FEE;
          
          static{   // Static Block
            OVERDRAFT_FEE = 29.95;
          }
      }
      ```

<br>

### Concept) Static Method
- Desc.)
  - A method defined by a class but not invoked on an object.
- e.g.) 
  - ```Math.sqrt()```
    - ```sqrt()``` is a method of the ```Math``` class, but a ```Math``` object cannot call it.
  - ```main``` method
    - ```main``` is always static.
- Prop.)
  - It has no implicit parameter.
  - You cannot directly access any instance variables.

<br>

### Concept) Static Import
- A variant of the ```import``` directive that lets you use static methods and variables without class prefixes.
- e.g.)
  ```java
  import static java.lang.System.*;     // Import every method of the System class.
  import static java.lang.Math.*;       // Import every method of the Math class.
  public class RootTester
  { 
    public static void main(String[] args)
    { 
        double r = sqrt(PI); // Instead of Math.sqrt(Math.PI)
        out.println(r);      // Instead of System.out
    }
  }
  ```


<br>

[Back to Big Java main](../../../main.md)