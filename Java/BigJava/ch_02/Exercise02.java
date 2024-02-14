import java.awt.Color;
import java.awt.Rectangle;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.time.DayOfWeek;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.swing.JFrame;

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

    public static void e0205(){
        Rectangle box = new Rectangle(5, 10, 20, 30);
        box.add(0, 0);

        System.out.println(box.toString());
    }

    public static void e0206(){
        String m = "Mississippi";
        m = m.replace('i', '!');
        m = m.replace('s', '$');

        System.out.println(m);
    }

    public static String ReplaceTester(String str){
        str = str.replace('e', '*');
        str = str.replace('o', 'e');
        str = str.replace('*', 'o');
        return str;
    }

    public static void e0207(){
        String s = "Hello World";
        System.out.println(ReplaceTester(s));
    }

    public static void e0208(){
        String str = "abc";

        StringBuilder sb = new StringBuilder(str);
        sb = sb.reverse();
        str = sb.toString();
        System.out.println(str);
    }

    public static void BrighterDemo(){
        //ArrayList<JFrame> jl = new ArrayList<>();
        Color c = new Color(50, 100, 150);
        int w = 400;
        for (int i=0; i<5; i++){
            JFrame frame = new JFrame();
            frame.setSize(w, w);
            frame.getContentPane().setBackground(c);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
            //jl.add(frame);

            w -= 40;

            c = c.brighter();
        }
    }

    public static void e0209(){
        BrighterDemo();
    }

    public static void DarkerDemo(){
        Color c = Color.RED;

        int w = 400;
        for (int i=0; i<5; i++){
            JFrame frame = new JFrame();
            frame.setSize(w, w);
            frame.getContentPane().setBackground(c);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
            //jl.add(frame);

            w -= 40;

            c = c.darker();
        }
    }

    public static void e0211(){
        DarkerDemo();
    }

    public static void e0212(){
        Random r = new Random();
        for (int i=0; i<10; i++){
            System.out.println(r.nextInt(1,7));
        }
    }

    public static void e0213(){
        Random r = new Random();
        System.out.println((float)r.nextInt(1000, 1996)/100);
    }

    public static void e0214(){
        Point2D.Double p1 = new Point2D.Double(3, 4);
        Point2D.Double p2 = new Point2D.Double(-3, -4);
        System.out.println(p1.distance(p2));
    }

    public static void p0201(){
        Rectangle[] R = new Rectangle[4];
        R[0] = new Rectangle(0, 0, 5, 10);
        R[1] = new Rectangle((int) (R[0].getX()+R[0].getWidth()),(int) R[0].getY(),(int) R[0].getWidth(),(int) R[0].getHeight());
        R[2] = new Rectangle((int) (R[0].getX()),(int) (R[0].getY()+R[0].getHeight()),(int) R[0].getWidth(),(int) R[0].getHeight());
        R[3] = new Rectangle((int) (R[0].getX()+R[0].getWidth()),(int) (R[0].getY()+R[0].getHeight()),(int) R[0].getWidth(),(int) R[0].getHeight());

        for (int i=0; i<4; i++){
            System.out.println(R[i].toString());
        }
    }
    
    public static void p0202(){
        Rectangle s1 = new Rectangle(100, 100, 50, 50);
        s1.grow(25, 25);
        System.out.println(s1);
        s1.translate(25, 25);
        System.out.println(s1);
    }

    public static Rectangle CenteredSquaresPrinter(Rectangle s, int n){
        double prev_x = s.getX();
        double prev_y = s.getY();
        s.grow(n*(-1), n*(-1));
        s.translate((int)((prev_x - s.getX())/2), (int)((prev_y - s.getY())/2));
        return s;
    }

    public static void p0203(){
        Rectangle s1 = new Rectangle(100, 100, 200, 200);
        System.out.println(s1);
        
        System.out.println(CenteredSquaresPrinter(s1, 50));

    }

    public static void main(String[] args){
        p0203();        
    }
}