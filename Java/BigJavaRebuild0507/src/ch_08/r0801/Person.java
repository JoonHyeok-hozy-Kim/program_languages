package ch_08.r0801;

import java.util.ArrayList;

public class Person {
    static private int PERSONID = 1;
    protected int personID;
    protected String name;
    protected ArrayList<Ride> rideList = new ArrayList<>();

    public Person(String name){
        this.personID = this.PERSONID++;
        // System.out.printf("A Person created. (ID : %d)\n", this.personID);
        this.name = name;
    };

    public void sayHi(){
        System.out.println("Hi");
    }

    public String getName(){
        return this.name;
    }

    public void addRide(Ride ride){
        this.rideList.add(ride);
    }

    public String listRides(){
        String result = "<Ride List>\n";
        for (Ride r: this.rideList){
            result += r.getRideSummaryString();
            result += "\n";
        }
        result += "\n";
        return result;
    }
}
