[Back to Big Java main](../../main.md)

# 3.1 Instance Variables and Encapsulation
### Concept) Instance Variable
- Def.)
  - An **instance variable** is a storage location that is present in each object of the class.
    - where an **instance of a class** is an **object of the class**.
- Prop.)
  - Instance variables are generally declared with the access specifier ```private```.
    - ```private``` : they can be accessed **only** by the methods of the same class.
- e.g.)
  ```java
  public class Counter{
    private int value; // This is an instance_variable.
  }
  ```

<br>

### Concept) Method
- e.g.) ```void``` case
  ```java
  public class Counter{
    public void click(){
        value += 1;         // Recall that value was private!
    }
  }
  ```
- e.g.) ```return``` case
  ```java
  public class Counter{
    public int getValue(){
        return value     // Recall that value was private!
    }
  }
  ```

<br>

### Concept) Encapsulation
- Def.)
  - The process of hiding implementation details while publishing an interface
- cf.)
  - In Java, the class construct provides encapsulation.
    - The ```public``` methods of a class are the interface through which the ```private``` implementation is manipulated.


<br>

[Back to Big Java main](../../main.md)