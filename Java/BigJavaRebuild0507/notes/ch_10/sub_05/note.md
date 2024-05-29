[Back to Big Java main](../../../main.md)

# 10.5 Inner Classes
### Concept) Inner Class
- Def.)
  - A class that is declared inside another class, such as the AreaMeasurer class in this example, is called an **inner class**.
  - It can be declared inside a method or an enclosing class
    - Inside a method
      ```java
      public class MeasurerTester{
        public static void main(String[] args) {
            class AreaMeasurer implements Measurer{
                // Inner class
            }
            
            Measurer areaMeas = new AreaMeasurer();
            double averageArea = Data.average(rects, areaMeas);
            
        }
      }
      ```
    - Inside an enclosing class
      ```java
      public class MeasurerTester{
        class AreaMeasurer implements Measurer{
            // Inner class
        }

        public static void main(String[] args) {
            
            Measurer areaMeas = new AreaMeasurer();
            double averageArea = Data.average(rects, areaMeas);
            
        }
      }
      ```

<br><br>

### Concept) Anonymous Class
- Desc.)
  - In case a single object of a class will be constructed and never be reused, this class can be implemented as an anonymous class.
- Syntax)
  ```java
  public static void main(String[] args){
    Rectangle[] rectangles = new Rectangle[3];
    // Add the Rectangle objects to rectangles.

    Measurer m = new Measurer() {
        public double measure(Object object){
            Rectangle r = (Rectangle) object;
            return r.getWidth() * r.getHeight();
        }
    }

    double result = Data.average(rectangles, m)
  }
  ```

<br>

[Back to Big Java main](../../../main.md)