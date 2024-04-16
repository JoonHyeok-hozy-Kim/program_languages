package exercise;

public class RandomGenerator {
    private int currentRandom;
    private int a;
    private int b;
    private int m;

    public RandomGenerator(int seed, int a, int b, int m){
        if (m == Math.pow(2, 32)) m = 1;
        else this.m = m;
        this.a = a;
        this.b = b;
    }

    public int generate(){
        currentRandom = (currentRandom * a + b) % m;
        return currentRandom;
    }
}
