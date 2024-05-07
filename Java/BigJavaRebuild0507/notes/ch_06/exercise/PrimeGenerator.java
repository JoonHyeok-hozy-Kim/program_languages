package exercise;

public class PrimeGenerator{
    private int prevPrime;
    private int upperBound;

    public PrimeGenerator(int upperBound){
        this.upperBound = upperBound;
        this.prevPrime = 1;
    }

    public int nextPrime(){
        while (prevPrime <= upperBound){
            prevPrime++;
            if (this.isPrime()){
                return prevPrime;
            }
        }
        return -1;
    }

    public boolean isPrime(){
        for (int i=2; i<prevPrime; i++){
            if (prevPrime % i == 0){
                return false;
            }
        }
        return true;
    }
}