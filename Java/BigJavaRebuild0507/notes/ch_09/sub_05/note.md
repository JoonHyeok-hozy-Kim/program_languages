[Back to Big Java main](../../../main.md)

#  9.5 Object: The Cosmic Superclass
### Concept) Object Class
- Desc.)
  - In Java, every class that is declared without an explicit extends clause automatically extends the class `Object`. 
    - i.e.) `Object` is the direct or indirect superclass of every class in Java
  - General methods defined by the `Object` class.
    - [`toString`](#concept-the-tostring-method)
    - [`equals`](#concept-the-equals-method)
    - [`hashCode`](#concept-the-hashcode-method)

<br>

#### Concept) The toString Method
- Desc.)
  - The `toString` method returns a string representation for each object.
- e.g.)
  ```java
  Rectangle box = new Rectangle(5, 10, 20, 30);
  String s = box.toString();
  ```
- Prop.)
  - The compiler can invoke the `toString` method, because it knows that every object has a `toString` method
     - Why?)
       - Every class extends the Object class, and that class declares `toString`.
  - If not overridden, the target object's [hashcode](#concept-the-hashcode-method) will be returned.

<br>

#### Concept) The equals Method
- Desc.)
  - It checks whether two objects have the same contents.

<br>

#### Concept) The hashCode Method
- Desc.)
  - The hash code can be used to tell objects apart — different objects are likely to have differ ent hash codes.

<br>

#### Concept) The instanceOf Operator
- Desc.)
  - An operator that checks whether an object is an instance of a class.
  - We can use this to prevent the “class cast” exception.  
    - e.g.)
      ```java
      ChoiceQuestion cq = new ChoiceQuestion();
      Question q = cq; // OK    <- Here, q is already assigned.
      Object obj = cq; // OK

      if (obj instanceOf Question){
        Question q = (Question) obj // <- Second assigning.
      }
      ```





<br>

[Back to Big Java main](../../../main.md)