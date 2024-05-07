import java.awt.Rectangle;

public class TesterHozy {
    public static void main(String[] args){
        Rectangle box = new Rectangle(5, 10, 20, 30);
        System.out.println(box.getX());

        box.translate(20, 20);
        System.out.println(box.getX());
    }
}
