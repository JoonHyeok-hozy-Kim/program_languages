import java.util.Random;
import java.util.stream.IntStream;

public class APITest{
    public static void main(String[] args){
        Random r = new Random();
        for (int i=0; i<10; i++){
            int x = r.nextInt(10);
            if (x != 10){
                System.out.println(x);
            }
        }
        
    }
}