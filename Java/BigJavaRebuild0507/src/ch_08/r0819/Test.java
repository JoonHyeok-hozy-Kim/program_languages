package ch_08.r0819;

import java.util.Arrays;

public class Test {
    public static void falseSwap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
    }

    public static void realSwap(int[] A){
        int temp = A[0];
        A[0] = A[1];
        A[1] = temp;
    }

    public static void main(String args[]){
        int x = 3;
        int y = 4;
        falseSwap(x, y);
        System.out.println(x + " " + y);

        int[] X = {3, 4};
        realSwap(X);
        System.out.println(Arrays.toString(X));
    }
}
