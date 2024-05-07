[Back to Big Java main](../../../main.md)

# 1.6 Errors
### Concept) Compile-Time Error (Syntax Error)
- Desc.)
  - Something is wrong according to the rules of the language and the compiler finds it.
  - When the compiler finds one or more errors, it refuses to translate the program into JVM instructions
    - No program you can run!
  - You must fix the error and compile again.
- e.g.)
  ```java
  System.ou.println("Hello World")  // error_message : “Cannot find symbol ou”
  ```
  ```java
  public class HelloPrinter
  { 
    public static void Main(String[] args)  // Main is NOT main!
    { 
      Systsem.out.println("Hello, World!");
    }
  }
  ```

<br>

### Concept) Run-Time Error (Logic Error)
- Desc.)
  - The program is syntactically correct and does something, but it doesn’t do what it is supposed to do.
  - Some kinds of run-time errors are so severe that they generate an **exception**: an error message from the Java virtual machine.
- e.g.)
  ```java
  System.out.println(Hello, Word!)  // No error_message. Just the typo, not "World"
  ```
  - The program will compile and run, but its output will be wrong.
  ```java
  System.out.println(1/0)  // error_message : “Division by zero”
  ```
  - 

<br>



<br>

[Back to Big Java main](../../../main.md)