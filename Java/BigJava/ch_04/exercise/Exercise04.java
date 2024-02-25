package exercise;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

import javax.swing.text.PlainView;

public class Exercise04{
    public static void r0401(){
        final int DAYS_PER_WEEK = 7;
        int daysUntilEndOfSemester;
        final double inchInCm;
        double tallestHeightCm;
    }

    public static void r0405(){
        double s0=0;
        double v0=0;
        double t=0;
        double g=0;

        double s = s0+v0*t+(1/2)*g*Math.pow(t, 2);

        double PV=0;
        double INT=0;
        int YRS=0;

        double FV = PV * Math.pow((1+INT/100), YRS);

        double a=0;
        double p=0;
        double m1=0;
        double m2=0;

        double G = 4 * Math.pow(Math.PI, 2) * Math.pow(a, 3) / (Math.pow(p, 2) * (m1+m2));

        double b=0;
        double gamma = 0;
        
        double c = Math.sqrt(Math.pow(a, 2)+Math.pow(b, 2)-2*a*b*Math.cos(gamma));
    }

    public static void r0406(){
        operations0406(2, 3);
        operations0406(3, 2);
        operations0406(2, -3);
        operations0406(3, -2);
        operations0406(-3, 2);
        operations0406(-3, -2);
    }

    public static void operations0406(int a, int b){
        System.out.printf("%f\t", Math.pow(a, b));
        System.out.printf("%d\t", Math.max(a, b));
        System.out.printf("%d\t", a/b);
        System.out.printf("%d\t", a%b);
        System.out.printf("%d\t\n", Math.floorMod(a, b));
    }

    public static void r0407(){
        System.out.println(AngleTurn(100, 50));
        System.out.println(AngleTurn(100, 400));
        System.out.println(AngleTurn(100, -180));
    }

    public static double AngleTurn(double dir, double turn){
        while (turn < 0){
            turn = turn + 360;
        }
        return (dir + turn) % 360;
    }

    public static void r0416(){
        printer0416("Harry");
        printer0416("a");
        printer0416("");
    }

    public static void printer0416(String str){
        int s = 0;
        int e = str.length();

        if (str.length() > 0){
            System.out.print(str.charAt(s)+" ");
            System.out.print(str.charAt(e-1)+" ");
            if (s+1 < e-1){
                System.out.print(str.substring(s+1, e-1));
            }        
        }
        System.out.println();
    }

    public static void r0417(){
        initialPrinter("Harold James Morgan");
    }

    public static void initialPrinter(String str){
        String[] l = str.split("\s");
        for (int i=0; i<l.length; i++){
            System.out.print(l[i].charAt(0));
        }
    }

    public static void r0418(){
        firstLastDigitPrinter(1234);
        firstLastDigitPrinter(50000);
        firstLastDigitPrinter(4);
    }

    public static void firstLastDigitPrinter(int n){
        int last = n % 10;
        while (n > 10){
            n /= 10;
        }
        System.out.printf("%d %d\n", n, last);
    }

    public static void r0423(){
        System.out.println(pieAreaCalculator(12, 10));
    }

    public static double pieAreaCalculator(double diameter, double chord){
        double h1 = Math.pow(diameter/2, 2);
        h1 -= Math.pow((chord/2), 2);
        h1 = Math.sqrt(h1);

        double S = Math.pow(diameter/2, 2);
        S *= Math.asin((chord/2) / (diameter/2));
        S -= (chord/2) * h1;

        return S;
    }
    
    public static void r0427(){
        System.out.println(2.0-1.1);
        System.out.println(65536 * 65536);
        System.out.println(1.0E6 * 1.0E6);
        System.out.println(1_000_000L * 1_000_000L);
    }

    public static void r0428(){
        BigInteger bi = new BigInteger("3");
        BigDecimal bd = new BigDecimal("3.0");
        BigInteger bit = new BigInteger("1000");
        BigDecimal bdt = new BigDecimal("1000");

        for (int i=0; i<3; i++){
            bi = bi.multiply(bit);
            bd = bd.multiply(bdt);
        }

        System.out.println(bi.toString());
        System.out.println(bd.toString());
    }

public static void e0401(){
    dimensionsInMm(8.5, 11);
}

public static void dimensionsInMm(double width, double height){
    final double mmPerInch = 25.4;
    System.out.printf("%.2f X %.2f", width*mmPerInch, height*mmPerInch);
}

public static void e0402(){
    dimAndDiag(8.5, 11);
}

public static void dimAndDiag(double width, double height){
    final double mmPerInch = 25.4;
    double inchWidth = width*mmPerInch;
    double inchHeight = height*mmPerInch;
    double diag = Math.sqrt(Math.pow(inchWidth, 2)+Math.pow(inchHeight, 2));
    System.out.printf("%.2f X %.2f, %.2f", inchWidth, inchHeight, diag);
}

public static void e0403(){
    pow0403(2);
}

public static void pow0403(int n){
    int m = n;
    for (int i=0; i<2; i++){
        m *= n;
        System.out.println(m);
    }
    System.out.println(Math.pow(n, 4));
}

public static void e0405(){
    numDisplay0405(20, 25);
}

public static void numDisplay0405(int a, int b){
    System.out.printf("Sum: \t\t %d\n", a+b);
    System.out.printf("Difference: \t %d\n", a-b);
    System.out.printf("Product: \t %d\n", a*b);
    System.out.printf("Average: \t %.2f\n", (double) (a+b)/2);
    System.out.printf("Distance: \t %d\n", Math.abs(a-b));
    System.out.printf("Maximum: \t %d\n", Math.max(a, b));
    System.out.printf("Minimum: \t %d\n", Math.min(a, b));
}

public static void e0412(){
    
    String home = System.getProperty("user.dir");
    System.out.println(home);
}

public static void e0413(){
    Scanner scanner = new Scanner(System.in);
    System.out.print("Please enter an integer between 1,000 and 999,999: ");
    String numStr = scanner.next();
    String[] l = numStr.split(",");
    for (int i=0; i<l.length; i++){
        System.out.print(l[i]);
    }
}

public static void e0414(){
    Scanner scanner = new Scanner(System.in);
    System.out.print("Please enter an integer between 1,000 and 999,999: ");
    int n = scanner.nextInt();

    Stack<Number> s = new Stack<>();
    while (n > 0){
        s.push(n % 1000);
        n /= 1000;
    }

    while (!s.empty()){
        System.out.printf("%d", s.pop());
        if (!s.empty()){
            System.out.print(",");
        }
    }
}

public static void e0415(){
    String bottom = "+";
    String comb = "|";

    int width = 3;
    int height = 3;

    for (int i=0; i<width; i++){
        bottom += "--+";
        comb += "  |";
    }

    System.out.println(bottom);
    for (int i=0; i<height; i++){
        System.out.println(comb);
        System.out.println(bottom);
    }
}

public static void e0416(){
    Scanner scanner = new Scanner(System.in);
    System.out.print("Input an integer: ");

    int n = scanner.nextInt();
    Stack<Number> s = new Stack<>();

    while (n>0){
        s.push(n%10);
        n /= 10;
    }

    while (! s.empty()){
        System.out.printf("%d ", s.pop());
    }
}

public static void e0417(){
    Scanner scanner = new Scanner(System.in);
    System.out.print("Please enter the first time: ");
    int fTime = scanner.nextInt();
    System.out.print("Please enter the second time: ");
    int sTime = scanner.nextInt();

    int temp;

    if (sTime >= fTime){
        temp = timeDiff0407(fTime, sTime);
    } else{
        temp = timeDiff0407(fTime, 2400);
        temp += timeDiff0407(0, sTime);
        if (temp%100 >= 60){
            temp += 100;
            temp -= 60;
        }
    }

    System.out.printf("%d hours %d minutes\n", temp/100, temp%100);
}

public static int timeDiff0407(int fTime, int sTime){
    int hour = sTime / 100 - fTime / 100;
    int min = sTime % 100 - fTime % 100;

    if (min < 0){
        hour -= 1;
        min += 60;
    }

    return hour * 100 + min;
}

public static void e0419(){
    HashMap<Number, String> map = new HashMap<>();
    map.put(1, "January");
    map.put(2, "February");
    map.put(3, "March");
    map.put(4, "April");
    map.put(5, "May");
    map.put(6, "June");
    map.put(7, "July");
    map.put(8, "August");
    map.put(9, "September");
    map.put(10, "October");
    map.put(11, "November");
    map.put(12, "December");

    System.out.println(map.get(3));
}

public static void e0420(){
    final int width = 4;
    final int truncHeight = 3;
    for (int i=0; i<width; i++){
        for (int j=0; j<width-1-i; j++){
            System.out.print(" ");
        }
        System.out.print("/");
        for (int j=0; j<i; j++){
            System.out.print("  ");
        }        
        System.out.print("\\");
        for (int j=0; j<width-1-i; j++){
            System.out.print(" ");
        }
        System.out.println("");
    }
    for (int i=0; i<width; i++){
        System.out.print("--");
    }
    System.out.println("");

    for (int i=0; i<truncHeight; i++){
        int margin = width - 2;
        for (int j=0; j<margin; j++){
            System.out.print(" ");
        }
        System.out.print("\"  \"");
        for (int j=0; j<margin; j++){
            System.out.print(" ");
        }
        System.out.println("");
    }
}

public static void p0401(){
    final double milesPerYear = 15000;
    double cost1 = totalCost0401(0, milesPerYear, 0, 0, 0);
}

public static double totalCost0401(double costOfCar, double milesPerYear, double gasPrice, double efficiencyMilesPerGallon, double resaleValue){
    return costOfCar + gasPrice * (milesPerYear / efficiencyMilesPerGallon) * 5 - resaleValue;
}

public static void p0403(){
    Point p1 = Point(0.0, 0.0);
}

    public static void main(String[] args){
        e0420();
    }
}