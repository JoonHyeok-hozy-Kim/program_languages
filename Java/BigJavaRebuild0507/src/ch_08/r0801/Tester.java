package ch_08.r0801;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Tester {
    public static void main(String[] args){
        ArrayList<Driver> driverGroup = new ArrayList<>();
        ArrayList<Rider> riderGroup = new ArrayList<>();

        String[] driverNames = {"Daniel", "David", "Donald"};
        String[] riderNames = {"Rachel", "Regina", "Riley"};
        String[] locationNames = {
            "South Korea", "United States", "China", "Japan", "Canada", "Australia", "United Kingdom", "France", "Germany", "India"            
        };
        Random r = new Random();

        for (int i=0; i<3; i++){
            Driver dTemp = new Driver(driverNames[i]);
            driverGroup.add(dTemp);

            Rider rTemp = new Rider(riderNames[i]);
            riderGroup.add(rTemp);
        }

        RideRate rr = new RideRate(100);

        ArrayList<Location> locationsList = new ArrayList<>();
        for (String lName: locationNames){
            Location lTemp = new Location(lName, r.nextDouble(100), r.nextDouble(100));
            // System.out.println(lTemp.getLocationInfo());
            locationsList.add(lTemp);            
        }

        Ride r1 = new Ride(driverGroup.get(0), riderGroup.get(0), locationsList.get(0), locationsList.get(1), rr);
        r1.showRideInfo();

        driverGroup.get(0).showDriverInfo();
        driverGroup.get(0).listRides();

        riderGroup.get(0).showRiderInfo();
        System.out.println(riderGroup.get(0).listRides());

    }
}
