package sub_09;
import java.util.Random;

public class Die{
    private Random generator;
    private int sides;

    public Die(int s){
        sides = s;
        generator = new Random();
    }

    public int cast(){
        return 1 + generator.nextInt(sides);
    }
}