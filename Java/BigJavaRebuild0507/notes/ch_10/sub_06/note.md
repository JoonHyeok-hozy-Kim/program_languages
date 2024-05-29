[Back to Big Java main](../../../main.md)

# 10.6 Mock Objects
### Concept) Mock Object
- Desc.)
  - When you work on a program that consists of multiple classes, you often want to test some of the classes before the entire program has been completed. 
  - A very effective technique for this purpose is the use of mock objects.
  - A **mock object** provides the same services as another object, but in a simplified manner. 
- e.g.)
  - Suppose the `GradeBook` class has three methods.
    - [GradeBook](../../../src/ch_10/objects/MockObject/GradeBook.java)
  - Then we want another class `GradingProgram` that manipulates a `GradeBook` object.
    - Here, `GradingProgram` calls methods of the `GradeBook` class.
    - We want to test the `GradingProgram` class without having a fully functional `GradeBook` class.
  - To achieve this, we can use a mock object.
  - How?)
    - Declare an interface type with the same methods that the `GradeBook` class provides.
      - [IGradeBook](../../../src/ch_10/objects/MockObject/GradeBook.java)
    - Create a `MockGradeBook` class that implements `IGradeBook`.
      - [MockGradeBook](../../../src/ch_10/objects/MockObject/MockGradeBook.java)
    - Test a `MockGradeBook` object in the `GradingProgram` program.


<br>

[Back to Big Java main](../../../main.md)