[Back to Big Java main](../../../main.md)

# 8.2 Designing Good Methods
### 8.2.1 Providing a Cohesive Public Interface
#### Concept) Cohesiveness
- A class should represent a single concept. 
- All interface features should be closely related to the single concept that the class represents. 
- Such a public interface is said to be **cohesive**.

<br>

### 8.2.2 Minimizing Dependencies
#### Concept) Dependency
- Many methods need other classes in order to do their jobs.

<br>

#### Concept) Unified Modeling Language (UML)
- **UML** is a notation for object-oriented analysis and design.
- The UML notation distinguishes between **object diagrams** and **class diagrams**. 
- In an **object diagram** the class names are underlined.
- In a **class diagram** 
  - the class names are not underlined.
  - you denote dependency by a dashed line with a ```->``` shaped open arrow tip that points to the dependent class.

<br>

### 8.2.3 Separating Accessors and Mutators
#### Concept) Mutator Method
- A mutator method changes the state of an object.

<br>

#### Concept) Accessor Method
- An accessor method asks an object to compute a result, without changing the state.

<br>

#### Concept) Immutable Class
- A class that is designed to have only [accessor methods](#concept-accessor-method) and no [mutator methods](#concept-mutator-method) at all.
- e.g.) ```String``` of Java
  - No method in the String class can modify the contents of a string. 
  - e.g.) The ```toUpperCase``` method does not change characters from the original string. 
    - Instead, it constructs a new string that contains the uppercase characters.
- It is still a good idea to cleanly separate accessors and mutators to avoid accidental mutation.

<br>

### 8.2.4 Minimizing Side Effects
#### Concept) Side Effect
- Desc.)
  - A side effect of a method is any kind of **modification** of data that is observable outside the method. 
  - Mutator methods have a side effect, namely the modification of the implicit parameter. 
- e.g.) Mutining other objects
  - ```System.out``` object
    ```java
    public void printBalance(){
      System.out.println("The balance is now $" + balance); // This mutates the System.out object!
    }
    ```
    - Instead, keep classes free from input and output operations.
    - Concentrate input/output in one place such as the ```main``` method.

<br><br>

#### Concept) Consistency
- Desc.)
  - When you have a set of methods, follow a consistent scheme for their names and parameter variables. 

<br>

#### Concept) Call by Value
- In Java, parameter variables are initialized with the values of the argument expressions. 
- When the method exits, the parameter variables are removed. Computer scientists refer to this call mechanism as “call by value”. 
```java
public class BankAccount
{
 public void transfer(double amount, double otherBalance) 
 {
 balance = balance - amount;
 otherBalance = otherBalance + amount; 
 // Won’t update the argument
 } 
}
```

<br>

#### Concept) Call by Reference
- A Java method can mutate an object when it receives an object reference as an argument.
```java
public class BankAccount
{
  public void transfer(double amount, BankAccount otherAccount)
  {
    balance = balance - amount;
    otherAccount.deposit(amount); 
  }
}
```
- However, a method cannot replace an object reference that is passed as an argument.
```java
public class BankAccount
{
  public void transfer(double amount, BankAccount otherAccount)
  { 
    balance = balance - amount;
    double newBalance = otherAccount.balance + amount;
    otherAccount = new BankAccount(newBalance); // Won’t work
  } 
}
```


<br>

[Back to Big Java main](../../../main.md)