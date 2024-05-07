[Back to Big Java main](../../../main.md)

# 4.5 Strings
### Concept) String
- Def.)
  - A sequence of characters : letters, numbers, punctuation, spaces, etc.

## 4.5.1 The String Type
### Concept) String Variable and String Literal
- e.g.)
  ```java
  String name = "Harry";
  ```
  - ```name``` is a string variable
  - ```"Harry"``` is a string literal
- cf.)
  - ```""``` : an empty string

<br><br>

## 4.5.2 Concatenation
- ```+``` operator
  - e.g.)
    ```java
    String fName = "Harry";
    String lName = "Morgan";
    String name = fName + lName;
    ```
- Implicit Casting
  - e.g.)
    ```java
    String str = "Agent";
    int num = 7;    // This becomes "7"
    String name = str + num;
    ```

<br><br>

## 4.5.3 String Input
- Prop.)
  - When a string is read with the ```next``` method, only one word is read. 
    - e.g.)
      ```java
      String.out.print("Please enter your name: ");
      String.name = in.next();

      // Suppose you typed in "Harry Morgan"
      System.out.println(name); // "Harry"
      name = in.next();
      System.out.println(name); // "Morgan"
      ```

<br><br>

## 4.5.4 Escape Sequences
- Quotation marks in a literal string
  ```java
  "He said \"Hello\"";
  ```
- Backslash
  ```java
  "C:\\Temp\\Secret.txt"
  ```
- A Newline Character
  ```java
  System.out.printf("Price: %10.2f\n", price);
  ```

<br><br>

## 4.5.5 Strings and Characters
- Prop.)
  - Strings are sequences of Unicode characters.
  -  In Java, a character is a value of the type ```char```.
     - ```'H'``` is a character, a value of type ```char```. 
     - ```"H"``` is a string containing a single character, a value of type ```String```.

<br><br>

## 4.5.6 Substrings
- ```substring``` method
  - e.g.)
    ```java
    String greeting = "Hello, World!";
    String sub = greeting.substring(0, 5); // sub is "Hello" 

    String tail = greeting.substring(7); // Copies all characters from position 7 on
    ```





<br>

[Back to Big Java main](../../../main.md)