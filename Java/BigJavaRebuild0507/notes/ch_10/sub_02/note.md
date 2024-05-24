[Back to Big Java main](../../../main.md)

# 10.2 Working with Interface Types
## 10.2.1 Converting from Classes to Interfaces
- Props.)
  - It is legal to convert from a `class` type to the `interface` type.
    - e.g.) Recall that [`BankAccount` `implements` `Measurable`](../../../src/ch_10/objects/Measurable/BankAccount.java)
      ```java
      BankAccount account = new BankAccount(1000);
      Measurable meas = new account;    // OK!
      ```

<br>

## 10.2.2 Invoking Methods on Interface Variables
- Prop.)
  - According to the [polymorphism](../../ch_09/sub_04/note.md#94-polymorphism) philosophy, the Java virtual machine locates the correct method by first looking at the `class` of the actual object, and then calling the method with the given name in that `class`.  
    - e.g.)
      ```java
      Measurable meas = new BankAccount(1000);
      double result = mes.getMeasure();
      ```
      - In this case, `BankAccount.getMeasure` is called!

<br>

## 10.2.3 Casting from Interfaces to Classes
If we are sure that an interface object refers to certain object type, we can **cast** it back to the class type.

#### E.g.)
Consider the case that we implemented a `static` method `larger` as follows.
```java
public class Measurable{
    public static Measurable larger(Measurable obj1, Measurable obj2){
        if (obj1.getMeasure() > obj2.getMeasure) return obj1;
        else return obj2;
    }
}
```
Then we ran a program as follows.
```java
Country uruguay = new Country("Uruguay", 176220);
Country thailand = new Country("Thailand", 513120);
Measurable max = larger(uruguay, thailand);
```
We know that the `max` interface object refers to the `Country` class type, while the compiler does not.   
Thus, we cannot call the `getName` method which is `Country`'s own method.   
In such case we can cast `max` to convert its type back to `Country`.
```java
Country maxCountry = (Country) max;
String name = maxCountry.getName();
```


<br>

[Back to Big Java main](../../../main.md)