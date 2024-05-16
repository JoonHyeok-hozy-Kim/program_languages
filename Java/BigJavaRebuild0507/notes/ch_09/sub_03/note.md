[Back to Big Java main](../../../main.md)

# 9.3 Overriding Methods
### Concept) Method Overriding
- Desc.)
  - The subclass inherits the methods from the superclass. 
  - If you are not satisfied with the behavior of an inherited method, you override it by **specifying a new implementation in the subclass**. 
- e.g.)
  - [Question](../../../src/ch_09/objects/Question/Question.java)'s `display()` method
  - [ChoiceQuestion](../../../src/ch_09/objects/Question/ChoiceQuestion.java)'s `display()` method
- Syntax)
  - How to call `super`'s constructors.
    ```java
    super(/*APPROPRIATE_PARAMETERS*/);
    ```
  - How to call `super`'s methods.
    ```java
    super.METHOD_NAME();
    ```

### Concept) Method Overloading
- Def.)
  - Two methods having the same name, provided they differ in their parameter types.



<br>

[Back to Big Java main](../../../main.md)