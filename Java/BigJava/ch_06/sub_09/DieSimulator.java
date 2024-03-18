package sub_09;

public class DieSimulator {
    public static void main(String[] aStrings){
        Die d = new Die(6);
        final int TRIES = 10;
        for (int i=1; i<= TRIES; i++){
            int n = d.cast();
            System.out.print(n + " ");
        }
        System.out.println();
    }
}
