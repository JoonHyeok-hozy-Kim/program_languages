[Back to Big Java main](../../main.md)

# 3.6 Local Variables
### Concept) Local Variable
- Def.)
  - A variable declared in the body of a method
- e.g.)
  ```java
  public double giveChange() {
    double change = payment - purchase; // change
    purchase = 0;
    payment = 0;
    return change;
  }
  ```
- Prop.)
  - Local and [parameter variables](#concept-parameter-variable) belong to methods. 
  - Life Cycle
    - When a method runs, its local and parameter variables come to life. 
    - When the method exits, they are removed immediately.
      - cf.) [Instance Variables](../sub_01/note.md#311-instance-variable)
        - Instance variables belong to objects, not methods. 
        - When an object is constructed, its instance variables are created. 
        - The instance variables stay alive until no method uses the object any longer. 
          - In Java, **garbage collector** periodically reclaims objects when they are no longer used.
  - You must initialize all local variables.
    - cf.) [Instance Variables](../sub_01/note.md#311-instance-variable) are initialized with a default value before a constructor is invoked.

<br>

### Concept) Parameter Variable
- Def.)
  - A variable declared in method headers
- e.g.)
  ```java
  public void receivePayment(double amount) {} // amount
  ```



<br>

[Back to Big Java main](../../main.md)