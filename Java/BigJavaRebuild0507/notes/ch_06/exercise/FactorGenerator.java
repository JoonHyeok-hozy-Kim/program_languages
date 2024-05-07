package exercise;

public class FactorGenerator {
    private int originalNumber;
    private int afterFactoring;
    private int currentFactor;

    public FactorGenerator(int numberToFactor){
        this.originalNumber = numberToFactor;
        this.afterFactoring = this.originalNumber;
        this.currentFactor = 2;
    }

    public boolean hasMoreFactors(){
        return this.afterFactoring > 1;
    }

    public int nextFactor(){
        if (! this.hasMoreFactors()){
            return 0;
        }

        while (this.afterFactoring % this.currentFactor != 0){
            currentFactor++;
        }

        this.afterFactoring /= this.currentFactor;

        return currentFactor;
    }
}
