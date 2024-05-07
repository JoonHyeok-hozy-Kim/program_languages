[Back to Big Java main](../../../main.md)

# 2.8 Object References
### Concept) Object Reference
- Def.)
  - The memory location of an object
- Desc.)
  - Objects can be very large. 
  - It is more efficient to  store only the memory location instead of the entire object.
- e.g.)
  - ```Rectangle box = new Rectangle();``` 
    - Desc.)
      - The ```new``` operator returned a reference to the ```Rectangle``` object, and that reference is stored in the ```box``` variable.
- cf.)
  - In Java, numbers are not objects.
    - Because numbers require little storage, it is more efficient to store them directly in a variable.

<br>

#### Experiment) Copying the Object Reference
- [Script](ObjectCopyTest.java)
- Result)
  - ```box2``` is an object reference copy of ```box1```.
  - Maneuvering ```box2``` affects ```box1```.


<br>

[Back to Big Java main](../../../main.md)