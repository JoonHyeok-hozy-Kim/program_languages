package ch_08.r0801;

public class Ride {
    private static int RIDEID = 1;
    protected int rideID;
    protected Driver drivenBy;
    protected Rider rodeBy;
    protected Location starting;
    protected Location destination;
    protected RideRate rate;

    public Ride(Driver driver, Rider rider, Location starting, Location destination, RideRate currRate){
        this.rideID = RIDEID++;
        this.drivenBy = driver;
        driver.addRide(this);
        this.rodeBy = rider;
        rider.addRide(this);
        this.starting = starting;
        this.destination = destination;
        this.rate = currRate;
    }

    public double getDistance(){
        return this.starting.getDistance(this.destination);
    }

    public double getTotaRate(){
        return this.getDistance() * this.rate.getRate();
    }

    public String doubleToString(double value, int precesion){
        String result = String.valueOf(value);
        return result.substring(0, result.indexOf(".") + precesion+1);
    }

    public void showRideInfo(){        
        System.out.println("\n<Ride Info>");
        System.out.println(" - Driver : " + this.drivenBy.getName());
        System.out.println(" - Rider : " + this.rodeBy.getName());
        System.out.println(" - From " + this.starting.getLocationInfo() + " / To " + this.destination.getLocationInfo() + " (" + doubleToString(this.getDistance(), 2) +")");
        System.out.println(" - Total Rate : " + doubleToString(this.getTotaRate(), 2));
        System.out.println();
    }

    public String getRideSummaryString(){
        String result = "[" + this.starting.getLocationInfo() + " -> " + this.destination.getLocationInfo() + "]";
        return result;
    }
}
