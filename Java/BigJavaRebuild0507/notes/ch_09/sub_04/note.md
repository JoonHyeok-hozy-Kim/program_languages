[Back to Big Java main](../../../main.md)

# 9.4 Polymorphism
### Concept) Dynamic Method Lookup and Polymorphism
- Desc.)
  - In Java, method calls are always determined by the type of the actual object, not the type of the variable containing the object reference.
- e.g.)
  - Consider [Question](../../../src/ch_09/objects/Question/Question.java) and [ChoiceQuestion](../../../src/ch_09/objects/Question/ChoiceQuestion.java).
  - `presentQuestion` is implemented below.
    ```java
    public static void presentQuestion(Question q){
        q.display();
        System.out.print("Your answer : ");
        Scanner in = new Scanner(System.in);
        String response = in.nextLine();
        System.out.println(q.checkAnswer(response));
    }
    ```
  - Suppose we used `ChoiceQuestion` as input.
    ```java
    ChoiceQuestion c = new ChoiceQuestion();
    presentQuestion(c);
    ```
  - In this case, the `display()` method called by `presentQuestion()` is `ChoiceQuestion`'s, not `Question`.
    - why?)
      - Dynamic Method Lookup!
- Prop.)
  - Dynamic method lookup allows us to **treat objects of different classes in a uniform way**.
  - This feature is called **polymorphism**.
    - i.e.) We ask multiple objects to carry out a task, and each object does so in its **own** way.

<br>

### Concept) Abstract Class / Abstract Method
- Desc.)
  - A class for which you cannot create objects is called an abstract class.
  - It exists to force programmers to override its method on its subclasses.
  - These methods are called the **abstract methods**.
- e.g.)
  - Implementation)
    ```java
    public abstract class Account{
      public void deductFees();
    }

    public class SavingsAccount extends Account{
      public void deductFees(){
          /* Need to be implemented! */
      }
    }
    ```
  - Instantiation)
    ```java
    Account a1; // Okay
    a1 = new Account(); // Error!
    a1 = new SavingsAccount(); // Okay
    a1 = null; // Okay
    ```

<br>

### Concept) Final Class / Final Method
- The reserved word `final` can be used to prevent other programmers from creating subclasses or from overriding certain methods.
- e.g.)
  - Final Class : `String`
    ```java
    public final class String{}
    ```
  - Final Method
    ```java
    public class SecureAccount extends BankAccount{ 
        //. . .
        public final boolean checkPassword(String password) { 
            //. . .
        }
    }
    ```

<br>

### Concept) Protected Access
- Desc.)
  - Protected data in an object can be accessed by the methods of the object’s class and all its subclasses.
  - Not suggested!
    - why?)
      - Any of the subclass methods can corrupt the superclass data.
      - Due to subclasses' dependencies, classes with protected variables are hard to modify. 
      - Protected variables are accessible not just by subclasses, but also by other classes in the same package.
- e.g.)
  ```java
  public class Question{
    protected String text;
  }
  ```


<br>

[Back to Big Java main](../../../main.md)