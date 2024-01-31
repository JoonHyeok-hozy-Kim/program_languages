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
      - Every Java **application** must have a ```main``` method.
      - The ```main``` method contains one or more instructions called statements.
        - Each statement ends in a semicolon (;).
        - When a program runs, the statements in the main method are executed one by one.
  - ```System.out.println``` : a method that prints a line of text
    - cf.) Whenever you call a method in Java, you need to specify
       1. The method you want to use (in this case, System.out.println).
       2. Any values the method needs to carry out its task (in this case, "Hello, World!"). 
          - The technical term for such a value is an **argument**. 
          - Arguments are enclosed in parentheses. 
          - Multiple arguments are separated by commas.
  - "Hello, World!" : a **string**.

<br>

[Back to Big Java main](../../main.md)