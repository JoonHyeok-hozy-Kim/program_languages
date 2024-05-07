import java.awt.Rectangle;

public class ObjectCopyTest {
    public static void main(String[] args){
        Rectangle box1 = new Rectangle(1,2,3,4);
        Rectangle box2 = box1;

        System.out.println(box1.getX());
        System.out.println(box2.getX());
        
        // Move box2
        box2.translate(10, 0);

        System.out.println(box1.getX());
        System.out.println(box2.getX());
    }
}
