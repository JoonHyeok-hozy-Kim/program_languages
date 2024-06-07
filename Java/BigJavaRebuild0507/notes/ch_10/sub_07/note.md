[Back to Big Java main](../../../main.md)

# 10.7 Event Handling
## 10.7.1 Listening to Events
### Concept) Event Listener
- Desc.)
  - Every program must indicate which events it needs to receive. 
  - It does that by installing **event listener** objects.
  - You must add an event listener object to the appropriate event sources.
    - cf) Event Source
      - An user-interface component that generates a particular event
      - Whenever the event occurs, the event source calls the appropriate methods of all attached event listeners.
  - e.g.) Button Click
    - Desc.)
      - Declare a [`ClickListener`](../../../src/ch_10/objects/ButtonClick/ClickListener.java) class.
        - Button listeners must belong to a class that implements the `ActionListener` interface.
            ```java
            public interface ActionListener{
                void actionPerformed(ActionEvent event);
            }
            ```
      - Display the button : [ButtonViewer](../../../src/ch_10/objects/ButtonClick/ButtonViewer.java)
        - Whenever the button is clicked, it calls `listener.actionPerformed(event);`.
        - You can think of the `actionPerformed` method as another example of a [callback](../sub_04/note.md#concept-callback).
          - why?)
            - The windowing toolkit calls the `actionPerformed` method whenever the button is pressed.

<br>

## 10.7.2 Using Inner Classes for Listeners
It is common to implement listener classes.
- Advantages)
  - Since listener classes tend to be very short, it is more complicated to make separate file.
  - Inner class's method can access instance variables and methods of the surrounding class.
    - It allows the inner class to access variables without having to receive them as constructor or method arguments.
- e.g.) [InvestmentViewer](../../../src/ch_10/objects/ButtonClick/InvestmentViewer.java)
  - `AddInterestListener` class is implemented as an inner class of the `InvestmentViewer` class.
  - The `AddInterestListener` object accesses the methods of `InvestmentViewer`'s `account` object.

<br>

### Concept) Lambda Expressions for Event Handling
- Recall that [lambda expressions](../sub_04/note.md#concept-lambda-expression) can be used to instantiate classes that implement functional interfaces.
  - i.e.) interfaces with a single abstract method
- This includes event handlers such as the `ActionListener` objects.
- e.g.)
  ```java
  button.addActionListener(
    (ActionEvent event) -> System.out.println("I was clicked!")
  );
  ```

<br>

[Back to Big Java main](../../../main.md)