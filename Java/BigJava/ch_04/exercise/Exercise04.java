package exercise;

import java.util.ArrayList;

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


    public static void main(String[] args){
        r0407();
    }
}