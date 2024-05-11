package ch_08.p0801;

public class Test {
    public static void main(String[] args){
        ComboLock c = new ComboLock(1, 2, 3);
        System.out.println(c.open());
        c.turnLeft(1);
        c.turnLeft(1);
        c.turnLeft(2);
        System.out.println(c.open());
        c.turnRight(1);
        System.out.println(c.open());
    }
}
