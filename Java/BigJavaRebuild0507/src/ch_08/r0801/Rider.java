package ch_08.r0801;

public class Rider extends Person {
    protected static int RIDERID = 1;
    protected int riderID;

    public Rider(String name){
        super(name);
        this.riderID = RIDERID++;
    }

    public void showRiderInfo(){
        System.out.println("\n<Rider Info>");
        System.out.println(" - PersonID : " + super.personID);
        System.out.println(" - DriverID : " + this.riderID);
        System.out.println(" - name : " + this.name);
        System.out.println();
    }
}
