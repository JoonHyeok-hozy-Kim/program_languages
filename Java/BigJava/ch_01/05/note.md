[Back to Big Java main](../../main.md)

# 1.5 Analyzing Your First Program
#### A Sample Java Source Code
```java
public class HelloPrinter
{
    public static void main(String[] args)
    {
        // Display a greeting in the console window.

        System.out.println("Hello, World!");
    }
}
```
- Desc.)
  - ```public class HelloPrinter``` : the declaration of a **class** called ```HelloPrinter```.
  - ```public``` denotes that the class is usable by the “public”.
    - Every source file can contain at most one public class
    - The name of the public class must match the name of the file containing the class. 
      - e.g.) "HelloPrinter.java" - ```class HelloPrinter```
  - ```java
    public static void main(String[] args)
    {
        ...
    }
    ```
    - This construction declares a method called ```main```.



<br>

[Back to Big Java main](../../main.md)