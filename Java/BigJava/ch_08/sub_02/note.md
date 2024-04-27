[Back to Big Java main](../../main.md)

# 8.2 Designing Good Methods
### 8.2.1) Providing a Cohesive Public Interface
#### Concept) Cohesiveness
- A class should represent a single concept. 
- All interface features should be closely related to the single concept that the class represents. 
- Such a public interface is said to be **cohesive**.

<br>

### 8.2.2) Minimizing Dependencies
#### Concept) Dependency
- Many methods need other classes in order to do their jobs.

<br>

#### Concept) Unified Modeling Language (UML)
- **UML** is a notation for object-oriented analysis and design.
- The UML notation distinguishes between **object diagrams** and **class diagrams**. 
- In an **object diagram** the class names are underlined.
- In a **class diagram** 
  - the class names are not underlined.
  - you denote dependency by a dashed line with a ```->``` shaped open arrow tip that points to the dependent class.

<br>

### 8.2.3) Separating Accessors and Mutators
#### Concept) Mutator Method
- A mutator method changes the state of an object.

<br>

#### Concept) Accessor Method
- An accessor method asks an object to compute a result, without changing the state.

<br>

#### Concept) Immutable Class
- A class that is designed to have only [accessor methods](#concept-accessor-method) and no [mutator methods](#concept-mutator-method) at all.
- e.g.) ```String``` of Java
  - No method in the String class can modify the contents of a string. 
  - e.g.) The ```toUpperCase``` method does not change characters from the original string. 
    - Instead, it constructs a new string that contains the uppercase characters.
- It is still a good idea to cleanly separate accessors and mutators to avoid accidental mutation.

<br>

#### Concept) 





<br>

[Back to Big Java main](../../main.md)