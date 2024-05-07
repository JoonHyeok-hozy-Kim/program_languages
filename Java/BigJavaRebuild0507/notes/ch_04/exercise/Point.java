package exercise;

public class Point {
    private double x;
    private double y;

    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }

    public double calculateDistance(Point other){
        double temp = 0;
        temp += Math.pow(this.x - other.getX(), 2);
        temp += Math.pow(this.y - other.getY(), 2);
        return Math.sqrt(temp);
    }
}
