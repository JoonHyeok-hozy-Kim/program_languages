package exercise;

import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class Exercise07{
    public static void r0701(){
        int[] a1 = new int[10];
        a1[0] = 17;
        a1[9] = 29;
        for (int i=0; i<a1.length; i++){
            if (i != 0 && i != 9) a1[i] = -1;
        }
        for (int i=0; i<a1.length; i++){
            a1[i] += 1;
        }
        for (int e : a1) System.out.println(e);
        for (int i=0; i<a1.length; i++){
            System.out.print(a1[i]);
            if (i != a1.length -1) System.out.print(", ");
        }
    }

    public static void r0703(){
        int[] a = new int[3];
        a[3] = 3;
    }

    public static void r0704(){
        Scanner scanner = new Scanner(System.in);
        int[] a = new int[10];
        for (int i=0; i<10; i++){
            System.out.printf("Input an integer(%d) : ", i+1);
            a[i] = scanner.nextInt();
        }
        for (int i=a.length-1; i>=0; i--){
            System.out.println(a[i]);
        }
    }

    public static void r0705(){
        int[][] aa = new int[7][];

        aa[0] = new int[10];
        for (int i=0; i<10; i++){
            aa[0][i] = i+1;
        }

        aa[1] = new int[11];
        for (int i=0; i<11; i++){
            aa[1][i] = 2*i;
        }

        aa[2] = new int[10];
        for (int i=0; i<10; i++){
            aa[2][i] = (i+1)*(i+1);
        }

        aa[3] = new int[10];
        for (int i=0; i<10; i++){
            aa[3][i] = 0;
        }

        aa[5] = new int[10];
        for (int i=0; i<10; i++){
            aa[5][i] = i%2;
        }

        aa[6] = new int[10];
        for (int i=0; i<10; i++){
            aa[6][i] = i%5;
        }

        for (int i=0; i<aa.length; i++){
            System.out.println(Arrays.toString(aa[i]));
        }
        
    }

    public static void r0708(){
        int size = 40;
        int[] values = new int[size];
        Random r = new Random();
        for (int i=0; i<size; i++) values[i] = r.nextInt(1, 100);
        Arrays.sort(values);
        System.out.println(Arrays.toString(values));

        values = new int[size];
        values[0] = r.nextInt(1, 100);
        for (int i=1; i<size; i++){
            boolean unique = false;
            int j = 0;
            int candidate = r.nextInt(1, 100);
            while (j < i){
                if (candidate != values[j]){
                    j++;
                } else {
                    candidate = r.nextInt(1, 100);
                    j = 0;
                }
            }
            values[i] = candidate;
        }
        Arrays.sort(values);
        System.out.println(Arrays.toString(values));
    }

    public static void r0709(){
        int[] a = new int[10];
        Random r = new Random();
        for (int i=0; i<a.length; i++) a[i] = r.nextInt(100);

        int minVal = a[0];
        int maxVal = a[0];

        for (int i=1; i<a.length; i++){
            minVal = Math.min(minVal, a[i]);
            maxVal = Math.max(maxVal, a[i]);
        }

        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
        System.out.printf("%d, %d", minVal, maxVal);
    }

    public static void r0710(){
        int[] a1 = new int[10];
        for (int i=0; i<a1.length; i++) a1[i] = (i+1) * (i%2 * 2 - 1);

        r0710A(a1);
        r0710B(a1);
        r0710C(a1);
    }

    public static void r0710A(int[] array){
        System.out.print("a. ");
        for (int i=0; i<array.length; i++){
            System.out.printf("%d ", array[i]);
        }
        System.out.println();
    }

    public static void r0710B(int[] array){
        int maxVal = array[0];
        for (int i=1; i<array.length; i++) maxVal = Math.max(maxVal, array[i]);
        System.out.printf("b. %d\n", maxVal);
    }

    public static void r0710C(int[] array){
        int negCnt = 0;
        for (int e : array){
            if (e < 0) negCnt++;
        }
        System.out.printf("c. %d\n", negCnt);
    }

    public static void r0720(){
        int[] a1 = new int[10];
        for (int i=0; i<a1.length; i++) a1[i] = (i+1) * (i%2 * 2 - 1);

        System.out.println(Arrays.toString(a1));
        r0720Rotator(a1);
        System.out.println(Arrays.toString(a1));
    }   

    public static void r0720Rotator(int[] arr){
        int starter = arr[0];

        for (int i=1; i<arr.length; i++) arr[i-1] = arr[i];

        arr[arr.length-1] = starter;
    }

    public static void r0721(){

    }

    public static void r0721NegEliminator(int[] arr){
        int initialLength = arr.length;
        int idx = 0;
        int jdx = 0;

        while (idx < initialLength){
            if (arr[idx] > 0){
                idx++;
                jdx++;
            } else {
                
            }
        }
    }

    public static void main(String[] args){
        r0720();
    }
}