[Back to Big Java main](../../../main.md)

# 10.1 Using Interfaces for Algorithm Reuse

<br>

## 10.1.1) Discovering an Interface Type
### E.g.) Implementing an Average Computing Service
- Consider the example that the algorithm for computing the average is the same in all cases, but the details of measurement differ.
- e.g.)
  - `BankAccount`
    ```java
    public static double average(BankAccount[] objects){
        double sum = 0;
        if (objects.length == 0) return 0;

        for (BankAccount obj: objects){
            sum += obj.getBalance();
        }
        return sum / objects.length;
    }
    ```
  - `Country`
    ```java
    public static double average(Country[] objects){
        double sum = 0;
        if (objects.length == 0) return 0;

        for (BankAccount obj: objects){
            sum += obj.getArea();
        }
        return sum / objects.length;
    }
    ```
- Possible Solution)
  - Implementing a common method `getMeasure()` both on `BankAccount` and `Country`.
    - Will not work.
      - In Java, we also must declare the type of the variable `obj`.
      - Thus, we need a new type called the [interface type]().

<br><br>

## 10.1.2) Declaring an Interface Type
### Concept) Interface Type
- Desc.)
  - In Java, an interface type is used to specify required operations. 
  - The declaration is similar to the declaration of a class.
    - List the methods that the interface requires.
    - need not supply an implementation for the methods.






<br>

[Back to Big Java main](../../../main.md)