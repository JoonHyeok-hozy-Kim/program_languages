package exercise;

public class Car {
    private double fuelEfficiency;
    private double fuelAmount;

    public Car(double efficiency){
        this.fuelEfficiency = efficiency;
        this.fuelAmount = 0;
    }

    public void drive(double distance){
        this.fuelAmount = Math.max(0, fuelAmount - distance / fuelEfficiency);
    }

    public double getGasInTank(){
        return this.fuelAmount;
    }

    public void addGas(double amount){
        this.fuelAmount += amount;
    }
}
