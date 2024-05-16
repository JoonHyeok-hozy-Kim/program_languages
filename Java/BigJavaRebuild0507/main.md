[Back to Main](../../README.md)

# Big Java, Early Objects
Cay Horstmann

## 1. Introduction
|No.|Chapter|Keywords|
|:-:|-|-|
|1.1|Computer Programs||
|1.2|The Anatomy of a Computer||
|1.3|[The Java Programming Language](notes/ch_01/03/note.md)||
|1.4|Becoming Familiar with Your Programming Environment||
|1.5|[Analyzing Your First Program](notes/ch_01/05/note.md)||
|1.6|[Errors](notes/ch_01/06/note.md)|Compile-Time Error (Syntax Error), Run-Time Error (Logic Error)|
|1.7|[Problem Solving: Algorithm Design](notes/ch_01/07/note.md)|Algorithm|
|-|[Exercise 01](notes/ch_01/ex/PracticeExcercises.java)||

<br>

## 2. Using Objects
|No.|Chapter|Keywords|
|:-:|-|-|
|2.1|[Objects and Classes](notes/ch_02/01/note.md)|Object, Class|
|2.2|[Variables](notes/ch_02/02/note.md)|Variable, Type, Name|
|2.3|[Calling Methods](notes/ch_02/03/note.md)|Public Interface, Method Overloading|
|2.4|[Constructing Objects](notes/ch_02/04/note.md)|Construction|
|2.5|[Accessor and Mutator Methods](notes/ch_02/05/note.md)|Accessor/Mutator Method|
|2.6|[The API Documentation](notes/ch_02/06/note.md)|Package, [Java API documentation](http://docs.oracle.com/javase/8/docs/api/index.html)|
|2.7|[Implementing a Test Program](notes/ch_02/07/note.md)|Test Program|
|2.8|[Object References](notes/ch_02/08/note.md)|Object Reference, ```new```|
|2.9|[Graphical Applications](notes/ch_02/09/note.md)|Frame( ```javax.swing.JFrame```), Component(```javax.swing.JComponent```)|
|2.10|[Ellipses, Lines, Text, and Color](notes/ch_02/10/note.md)|Ellipses, Circles, Points, Lines, Texts, Colors <br> Example : [FaceComponent.java](notes/ch_02/sub_10/FaceComponent.java), [FaceViewer.java](notes/ch_02/sub_10/FaceViewer.java)|
|-|[Exercise 02](notes/ch_02/Exercise02.java)|```Rectangle```, ```Random```, ```StringBuilder```, ```JFrame```, ```JOptionPane```, ```GregorianCalendar```, ```LocalDate```|

<br>

## 3. Implementing Classes
|No.|Chapter|Keywords|
|:-:|-|-|
|3.1|[Instance Variables and Encapsulation](notes/ch_03/sub_01/note.md)|- Instance Variable, Method, Encapsulation|
|3.2|[Specifying the Public Interface of a Class](notes/ch_03/sub_02/note.md)|- Constructor, Public Interface <br> - Commenting (javadoc)|
|3.3|[Providing the Class Implementation](notes/ch_03/sub_03/note.md)|- |
|3.4|[Unit Testing](notes/ch_03/sub_04/note.md)|- Unit Test|
|3.6|[Local Variables](notes/ch_03/sub_06/note.md)|- Local Variable, Parameter Variable|
|3.7|[The ```this``` Reference](notes/ch_03/sub_07/note.md)|- Implicit/Explicit Parameter<br>- ```this```|
|3.8|[Shape Classes](notes/ch_03/sub_08/note.md)|```JFrame```<br>- Car Example : [Car.java](notes/ch_03/sub_08/Car.java), [CarComponent.java](CarComponent.java), [CarViewer.java](CarViewer.java)|
|-|[Exercise 03](notes/ch_03/exercise/Exercise03.java)||

<br>

## 4. Fundamental Data Types
|No.|Chapter|Keywords|
|:-:|-|-|
|4.1|[Numbers](notes/ch_04/sub_01/note.md)|- Eight Primitive Types in Java : int, byte, short, long, double, float, char, boolean <br> - ```Integer.MAX_VALUE```, ```Integer.MIN_VALUE``` <br> - Number Literal, Overflow, ```BigInteger```, ```BigDecimal```, Floating-Point Number <br>- Constants (```final```)|
|4.2|[Arithmetic](notes/ch_04/sub_02/note.md)|- Arithmetic Operators :```+-*/``` <br>- Increment(```++```) Decrement(```--```)<br>- Division(```/```), Modulus(```%```)<br>- Powers(```Math.pow()```), Roots(```Math.sqrt()```)<br>- Casting|
|4.3|[Input and Output](notes/ch_04/sub_03/note.md)|- Prompt <br> - Formatted Output, ```System.out.printf()```, Format Specifier (```%d```, ```%f```)|
|4.5|[Strings](notes/ch_04/sub_05/note.md)|- Concatenation(```+```) <br>- String Input : ```in.next()```<br>- Substring : ```substring(s, e)```|
|-|[Exercise 04](notes/ch_04/exercise/Exercise04.java)||

<br>

## 5. Decisions
|No.|Chapter|Keywords|
|:-:|-|-|
|5.1|[The ```if``` Statement](notes/ch_05/sub_01/note.md)|- Conditional Operator|
|5.2|[Comparing Values](notes/ch_05/sub_02/note.md)|- Relational Operators <br> - Comparing Floating-Point Numbers, ```String```s, and Objects <br> - ```null```|
|5.3|Multiple Alternatives|-|
|5.4|[Nested Branches](notes/ch_05/sub_04/note.md)|- Block Scope <br>- Enumeration Type (```enum```)|
|5.5|Problem Solving: Flowcharts|-|
|5.6|[Problem Solving: Selecting Test Cases](notes/ch_05/sub_06/note.md)|- Black-Box Testing, White-Box Testing, Code Coverage <br> - ```Logger.getGlobal()```|
|5.7|Boolean Variables and Operators|- ```true```, ```false```, ```&&```, ```\|\|```, ```!```|
|5.8|Input Validation|-|
|-|[Exercise 05](notes/ch_05/exercise/Exercise05.java)||

<br>

## 6. Loop
|No.|Chapter|Keywords|
|:-:|-|-|
|6.1|[The ```while``` Loop](notes/ch_06/sub_01/note.md)|- ```while```|
|6.2|Problem Solving: Hand-Tracing|- |
|6.3|[The ```for``` Loop](notes/ch_06/sub_03/note.md)|- ```for```|
|6.4|[The ```do``` Loop](notes/ch_06/sub_04/note.md)|- ```do```|
|6.5|[Application: Processing Sentinel Values](notes/ch_06/sub_05/note.md)|- Sentinel|
|6.6|Problem Solving: Storyboards|- |
|6.7|Common Loop Algorithms|-|
|6.8|Nested Loops|-|
|6.9|[Application: Random Numbers and Simulations](notes/ch_06/sub_05/note.md)|- ```Random```|
|6.10|Using a Debugger|-|
|-|[Exercise 06](notes/ch_06/exercise/Exercise06.java)||

<br>

## 7. Arrays and Array Lists
|No.|Chapter|Keywords|
|:-:|-|-|
|7.1|[Arrays](notes/ch_07/sub_01/note.md)|- Declaration, Referencing, Usage in Methods, Partially Filled Array|
|7.2|[The Enhanced ```for``` Loop](notes/ch_07/sub_02/note.md)|- |
|7.3|[Common Array Algorithms](notes/ch_07/sub_03/note.md)|- |
|7.5|Problem Solving: Discovering Algorithms by Manipulating Physical Objects|- |
|7.6|[Two-Dimensional Arrays](notes/ch_07/sub_06/note.md)|- |
|7.7|[Array Lists](notes/ch_07/sub_07/note.md)|- Generic Class <br> - Wrapper Class, Auto-Boxing <br> - The Diamond Syntax|
|7.8|[Regression Testing](notes/ch_07/sub_06/note.md)|- |
|-|[Exercise 07](notes/ch_07/exercise07/Exercise07.java)||

<br>

## 8. Designing Classes
|No.|Chapter|Keywords|
|:-:|-|-|
|8.1|Discovering Classes|- |
|8.2|[Designing Good Methods](notes/ch_08/sub_02/note.md)|- Cohesive Public Interface <br> - Minimizing Dependencies <br> - Unified Modeling Language (UML) <br> - Mutator Method / Accessor Method <br> - Immutable Class <br> - Side Effect, Consistency, Call by Value, Call by Reference |
|8.3|Patterns for Object Data|- |
|8.4|[Static Variables and Methods](notes/ch_08/sub_04/note.md)|- Static Variable, Static Block, Static Constant <br> - Static Method <br> - Static Import|
|8.5|Problem Solving: Solve a Simpler Problem First|- |
|8.6|[Packages](notes/ch_08/sub_06/note.md)|- |
|8.7|Unit Test Frameworks|- JUnit|
|-|[Exercise 08](src/ch_08/)||

<br>

## 9. Inheritance
|No.|Chapter|Keywords|
|:-:|-|-|
|9.1|Inheritance Hierarchies|- |
|9.2|[Implementing Subclasses](notes/ch_09/sub_02/note.md)|- `super` vs `this`|
|9.3|[Overriding Methods](notes/ch_09/sub_03/note.md)|- Method Overriding <br> - Method Overloading|
|9.4|[Polymorphism](notes/ch_09/sub_04/note.md)|- Dynamic Method Lookup <br> - `abstract` : Abstract Class / Abstract Method <br> - `final` : Final Class / Final Method <br> - `protected` : Protected Access|






<br>



<br>

[Back to Main](../../README.md)