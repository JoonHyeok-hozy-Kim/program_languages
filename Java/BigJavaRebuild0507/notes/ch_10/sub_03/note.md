[Back to Big Java main](../../../main.md)

# 10.3 The Comparable Interface
### Concept) The Comparable Interface
- Desc.)
  - A standard Java library that compares to objects with its single method, `compareTo`.
  - The call `a.compareTo(b)` must return 
    - a negative number if `a` should come before `b`.
    - zero if `a` and `b` are the same.
    - a positive number if `b` should come before `a`.
  - If a class implements the `Comparable` interface, the array of this objects can be sorted.
    - e.g.)
      ```java
      BankAccount[] accounts = new BankAccount[3];
      accounts[0] = new BankAccount(10000);
      accounts[1] = new BankAccount(0);
      accounts[2] = new BankAccount(2000);
      Arrays.sort(accounts);
      ```
- e.g.)
  ```java
  public interface Comparable{
      int compareTo(Object otherObject);
  }
  ```
  ```java
  public class BankAccount implements Comparable{
      public int compareTo(Object otherObject){
          BankAccount other = (BankAccount) otherObject;
          if (this.balance < other.balance) return -1;
          else if (this.balance > other.balance) return 1;
          else return 0;
      }
  }
  ```
- Tips)
  - Use the `compare` method when comparing integers or floating-point numbers instead of directly subtracting them.
    - why?)
      - It can prevent overflow problem.
  - e.g.)
    ```java
    // Integer Case
    public class Person implements Comparable{
      private int id; 

      public int compareTo(Object otherObject){
        Person other = (Person) otherObject;
        return Integer.compare(this.id, other.id);
      }
    }
    
    // Floating Point Case
    public class BankAccount implements Comparable{
      private double balance; 

      public int compareTo(Object otherObject){
        BankAccount other = (BankAccount) otherObject;
        return Double.compare(this.balance, other.balance);
      }
    }
    ```

<br><br>


### Concept) The Cloneable Interface
- Desc.)
  - Using the `clone` method of the `Object` class, we can copy objects.
  - However, if the target object has a reference to other objects, the `clone` method shallow copies them.
    - There can be some problem related to this.
    - So there are required steps to implement `Cloneable`.
      - Make the class implement the `Cloneable` interface type.
      - In the clone method, call `super.clone()`. Catch the `CloneNotSupportedException` if the superclass is `Object`.
      - Clone any mutable instance variables.

- e.g.)
  ```java
  public class BankAccount implements Cloneable{
    public Object clone(){
      try {
        return super.clone();
      } catch (CloneNotSupportedException e){
        return null;
      }
    }
  }
  ```
  ```java
  public class Customer implements Cloneable{
    private String name;
    private BankAccount account;

    public Customer(String name, BankAccount account){
      this.name = name;
      this.account = account;
    }

    public Object clone(){
      try {
        Customer cloned = (Customer) super.clone();
        cloned.account = (BankAccount) account.clone();
        return super.clone();
      } catch (CloneNotSupportedException e){
        return null;
      }
    }
  }
  ```
  ```java
  BankAccount account = new BankAccount(1000);
  Customer customer = new Customer("AJ", account);
  
  Customer cloneCustomer = (Customer) customer.clone();
  ```


<br>

[Back to Big Java main](../../../main.md)