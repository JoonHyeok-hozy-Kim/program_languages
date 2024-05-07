package ch_08.r0801;

public class Location {
    private static int LOCATIONID = 1;
    protected int locationID;
    protected String name;
    protected double x;
    protected double y;

    public Location(String name, double x, double y){
        this.locationID = LOCATIONID++;
        this.name = name;
        this.x = x;
        this.y = y;
    }

    public String getName(){
        return this.name;
    }

    public double getDistance(Location other){
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.x - other.x, 2));
    }

    public String doubleToString(double value, int precesion){
        String result = String.valueOf(value);
        return result.substring(0, result.indexOf(".") + precesion+1);
    }

    public String getLocationInfo(){
        String xString = String.valueOf(this.x);
        xString = xString.substring(0, xString.indexOf(".") + 3);
        String yString = String.valueOf(this.y);
        yString = yString.substring(0, yString.indexOf(".") + 3);
        return this.name + "("+ this.doubleToString(x, 2) + ", " + this.doubleToString(y, 2) + ")";
    }
}
