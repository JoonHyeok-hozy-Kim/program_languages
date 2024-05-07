package ch_08.r0801;

import java.util.ArrayList;

public class Driver extends Person {
    protected static int DRIVERID = 1;
    protected int DriverID;

    public Driver(String name){
        super(name);
        this.DriverID = DRIVERID++;

    }

    public void showDriverInfo(){
        System.out.println("\n<Driver Info>");
        System.out.println(" - PersonID : " + super.personID);
        System.out.println(" - DriverID : " + this.DriverID);
        System.out.println(" - name : " + this.name);
        System.out.println(this.listRides());
        System.out.println();
    }
}
