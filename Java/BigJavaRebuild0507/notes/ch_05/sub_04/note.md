[Back to Big Java main](../../../main.md)

# 5.4 Nested Branches
### Concept) Block Scope
- Desc.)
  - A **block** is a sequence of statements that is enclosed in braces.
    - e.g.)
      ```java
      if (status = TAXABLE){
        /* A block started. */
        double tax = price * TAX_RATE;
        price = price + tax;
        /* A block ended. */
      }
      ```
  - In general, the scope of a variable is the part of the program in which the variable can be accessed. 
  - A variable with **block scope** is visible only inside a block.
    - However, if you need the variable outside the block, you must define it outside.
  - In Java, the scope of a local variable can never contain the declaration of another local variable with the same name.
    - e.g.)
      ```java
      double tax = 0;

      if (status = TAXABLE){
        double tax = price * TAX_RATE;  // Error!
        price = price + tax;
      }
      ```
  - However, you can have local variables with identical names if their scopes do not overlap.
    - e.g.)
      ```java
      if (status = TAXABLE){
        double tax = price * TAX_RATE;  // Error!
      } else {
        int tax = 1;
      }
      ```

<br>

### Concept) 
### Concept) Block Scope
- Desc.)
  - An enumeration type has a finite set of values.
- e.g.)
  ```java
  public enum FilingStatus { SINGLE, MARRIED, MARRIED_FILING_SEPARATELY };

  FilingStatus status = FilingStatus.SINGLE;

  if (status == FilingStatus.SINGLE){
    ...
  }
  ```


<br>

[Back to Big Java main](../../../main.md)