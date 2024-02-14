import java.awt.Rectangle;
import java.awt.geom.Line2D;
import java.util.Random;

public class Exercise02{
    public static void r0209(){
        String message = "hello";
        message = message.toUpperCase();
        System.out.println(message);
    }

    public static void r0210(){
        String message = "hello";
        message = message.replace(message, message.toUpperCase());        
        System.out.println(message);
    }

    public static void r0211(){
        String message = "Hello, world!!??...";

        message = message.replace('.', '\s');
        message = message.replace(',', '\s');
        message = message.replace('?', '\s');
        message = message.replace('!', '\s');     
        System.out.println(message);
    }

    public static void r0213(){
        Rectangle r1 = new Rectangle();
        Rectangle r2;
    }

    public static void r0214(){
        Rectangle r1 = new Rectangle(100, 100, 50, 50);
        String s1 = new String("Hello, Dave");
    }

    public static void r0215(){
        Rectangle r1 = new Rectangle(100, 100, 50, 50);
        String s1 = new String("Hello, Dave");
        Rectangle r2 = r1;
        String s2 = s1;
    }

    public static void r0216(){
        Rectangle square = new Rectangle(10, 20, 40,40);
        square.translate(10, 0);
    }

    public static void r0217(){
        Rectangle r1 = new Rectangle(20,20,40,40);
        Rectangle square1 = r1;
        Rectangle square2 = r1;

        double width = r1.getWidth();
        System.out.println(width);
    }

    public static void r0220(){
        String s1 = " abc";
        String s2 = "XYZ ";

        System.out.println(s1.concat(s2));
        System.out.println(s2.concat(s1));

        System.out.println(s1.trim());
        System.out.println(s2.trim());

        Rectangle r1 = new Rectangle(10, 20, 30, 40);
        System.out.println(r1.toString());
        
        Rectangle r2 = new Rectangle(10, 20, 300, 400);
        
        Random ran1 = new Random();
        System.out.println(ran1.nextFloat());
    }

    public static void e0201(){
        Rectangle r = new Rectangle(10, 20, 30, 40);
        double area = r.getWidth() * r.getHeight();
        System.out.println(area);
    }

    public static void e0202(){
        Rectangle r = new Rectangle(10, 20, 30, 40);
        double perimeter = r.getWidth() + r.getHeight();
        perimeter *= 2;
        System.out.println(perimeter);
    }

    public static void e0203(){
        String m = "Mississippi";
        System.out.println(m.length());

        m = m.replace("i", "ii");
        System.out.println(m);
        System.out.println(m.length());
        
        m = m.replace("ss", "s");
        System.out.println(m);
        System.out.println(m.length());
    }

    public static void e0204(){
        double area = 42;
        double perimeter = 42;

        double width = 0;
        double height = 0;
        double upper = 0.5;
        double lower = 0;
        double mid;
        double gap = 1;

        int rep_cnt = 100;

        while (gap > 0.001 && rep_cnt > 0){
            mid = (upper + lower) / 2;
            width = perimeter * mid / 2;
            height = perimeter * (1-mid) / 2;

            gap = width * height - area;
            // System.out.print("Gap : ");
            // System.out.println(gap);

            if (gap > 0){
                upper = mid;
            } else if (gap == 0){
                break;
            } else {
                lower = mid;
            }
            
            gap = Math.abs(gap);
            rep_cnt -= 1;
        }

        System.out.println(width);
        System.out.println(height);
        System.out.println(width+height);
        System.out.println(width*height);
    }


    public static void main(String[] args){
        e0204();
        
    }
}