package exercise;

public class Triangle {
    private Point p1;
    private Point p2;
    private Point p3;
    private double l1;
    private double l2;
    private double l3;
    private double a1;
    private double a2;
    private double a3;

    public Triangle(Point p1, Point p2, Point p3){
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;

        getLengths();
        getAngles();
    }

    public void getLengths(){
        this.l1 = p1.calculateDistance(p2);
        this.l2 = p2.calculateDistance(p3);
        this.l3 = p3.calculateDistance(p1);
    }

    public void getAngles(){
        this.a1 = calculateAngle(l1, l2, l3);
        this.a2 = calculateAngle(l2, l3, l1);
        this.a3 = calculateAngle(l3, l1, l2);
    }

    public double calculateAngle(double a, double b, double c){
        double cosValue = (a*a + b*b - c*c)/(2*a*b);
        return Math.acos(cosValue);
    }

    public void display(){
        System.out.printf("l1 : %f\n", l1);
        System.out.printf("l2 : %f\n", l2);
        System.out.printf("l3 : %f\n", l3);
        System.out.printf("a1 : %f\n", a1);
        System.out.printf("a2 : %f\n", a2);
        System.out.printf("a3 : %f\n", a3);
        System.out.printf("Perimeter : %f\n", (l1+l2+l3));
        System.out.printf("Area : %f\n", (l1 * l2 * Math.sin(a1))/2);
    }
}
