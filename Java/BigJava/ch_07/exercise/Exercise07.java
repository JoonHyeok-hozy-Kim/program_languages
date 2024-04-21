package exercise;

import java.util.ArrayList;
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
        int[] a1 = new int[10];
        for (int i=0; i<a1.length; i++) a1[i] = (i+1) * (i%2 * 2 - 1);
        System.out.println(Arrays.toString(a1));
        r0721NegEliminator(a1);
        System.out.println(Arrays.toString(a1));
    }

    public static void r0721NegEliminator(int[] arr){
        int initialLength = arr.length;
        int idx = 0;
        int jdx = 0;

        while (idx < initialLength){
            if (arr[idx] < 0){
                idx++;
            } else {
                arr[jdx] = arr[idx];
                idx++;
                jdx++;
            }
        }

        while (jdx < idx) {
            arr[jdx] = 0;
            jdx++;
        }
    }

    public static void r0722(){
        int[] a1 = new int[10];
        int insertNum = 5;
        for (int i=0; i<insertNum; i++) a1[i] = i*3+1;
        System.out.println(Arrays.toString(a1));
        r0722Insert(a1, insertNum, 5);
        System.out.println(Arrays.toString(a1));
    }

    public static void r0722Insert(int[] arr, int lastIdx, int num){
        int temp1;
        int temp2 = num;
        for (int i=0; i<lastIdx; i++){
            if (arr[i] < num) continue;
            temp1 = arr[i];
            arr[i] = temp2;
            temp2 = temp1;
        }
        arr[lastIdx] = temp2;
    }

    public static void r0723(){
        int[] a = new int[20];
        String lstr = "1 2 5 5 3 1 2 4 3 2 2 2 2 3 6 5 5 6 3 1";
        int idx = 0;
        for (String estr : lstr.split(" ")){
            a[idx] = Integer.valueOf(estr);
            idx++;
        }
        
        System.out.println(r0723LongestRun(a));
    }

    public static int r0723LongestRun(int[] arr){
        int runCnt = 0;
        int currCnt = 1;
        int currVal = arr[0];

        for (int i=1; i<arr.length; i++){
            if (arr[i] == currVal){
                currCnt++;
            } else {
                runCnt = Math.max(runCnt, currCnt);
                currCnt = 1;
                currVal = arr[i];
            }
        }
        
        return Math.max(runCnt, currCnt);
    }

    public static void makeCombination(int[] values, int n) {
        Random generator = new Random();
        int[] numbers = new int[values.length];
        for (int i = 0; i < numbers.length; i++) 
        { 
        numbers[i] = generator.nextInt(n); 
        }
        values = numbers;
    }

    public static void makeCombinationRevised(int[] values, int n) {
        Random generator = new Random();
        for (int i = 0; i < values.length; i++) 
        { 
            values[i] = generator.nextInt(n); 
        }
    }

    public static void r0724(){
        int[] v = new int[5];
        System.out.println(Arrays.toString(v));
        makeCombination(v, 100);
        System.out.println(Arrays.toString(v));
        makeCombinationRevised(v, 100);
        System.out.println(Arrays.toString(v));
    }

    public static class Point {
        private int x;
        private int y;

        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        public int getX(){
            return this.x;
        }
        
        public int getY(){
            return this.y;
        }

        public void setX(int x) {
            this.x = x;
        }

        public void setY(int y) {
            this.y = y;
        }

        public String toString(){
            return "(" + this.x + ", " + this.y + ")";
        }
    }

    public static class Rectangle {
        private Point standardPoint;
        private int width;
        private int height;

        public Rectangle(Point stdPnt, int w, int h){
            this.standardPoint = stdPnt;
            this.width = w;
            this.height = h;
        }

        public String toString(){
            String result = standardPoint.toString();
            result += " - h : " + this.height;
            result += " - w : " + this.width;
            return result;
        }
    }

    public static Rectangle getSmallestRectangle(Point[] p){
        int vertMin = p[0].getX();
        int vertMax = p[0].getX();
        int horiMin = p[0].getY();
        int horiMax = p[0].getY();

        for (int i=0; i<p.length; i++){
            vertMin = Math.min(vertMin, p[i].getX());
            vertMax = Math.max(vertMax, p[i].getX());
            horiMin = Math.min(horiMin, p[i].getY());
            horiMax = Math.max(horiMax, p[i].getY());
        }

        Rectangle result = new Rectangle(new Point(vertMin, horiMin), vertMax-vertMin, horiMax-horiMin);
        return result;
    }

    public static void r0725(){
        Point[] points = new Point[8];
        points[0] = new Point(-2, -3);
        points[1] = new Point(-1, -1);
        points[2] = new Point(1,1);
        points[3] = new Point(4,2);
        points[4] = new Point(1,4);
        points[5] = new Point(1,-1);
        points[6] = new Point(2,-5);
        points[7] = new Point(-6,-3);

        System.out.println(getSmallestRectangle(points).toString());
    }

    // 429

    public static void r0728(){
        int[] a = new int[10];
        Random seed = new Random();
        for (int i=0; i<a.length; i++) a[i] = seed.nextInt(a.length/2);
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
        
        System.out.println(Arrays.toString(r0728MostFrequent(a)));
    }

    public static int[] r0728MostFrequent(int[] arr){ 
        int[] numVals = new int[arr.length];
        int[] numCnts = new int[arr.length];
        int currIdx = 0;
        boolean found;
        for (int e : arr){
            found = false;
            for (int i=0; i<currIdx; i++){
                if (numVals[i] == e){
                    found = true;
                    numCnts[i]++;
                    break;
                }
            }
            if (!found){
                numVals[currIdx] = e;
                numCnts[currIdx] = 1;
                currIdx++;
            }
        }

        int[] resultArr = {numVals[0], numCnts[0]};
        for (int i=1; i<currIdx; i++){
            if (resultArr[1] < numCnts[i]) {
                resultArr[0] = numVals[i];
                resultArr[1] = numCnts[i];
            }
        }
        return resultArr;
    }

    public static void r0728Repeat(){
        for (int i=0; i<5; i++){
            r0728();
        }
    }

    public static void r0729(){
        int ROWS = 4;
        int COLUMNS = 4;
        int[][] values = new int[ROWS][COLUMNS];

        r0729FillWithZeroes(values);
        for(int[] e : values){
            System.out.println(Arrays.toString(e));
        }

        r0729FillAsCheckers(values);
        for(int[] e : values){
            System.out.println(Arrays.toString(e));
        }

        r0729TopBottomOnly(values);
        for(int[] e : values){
            System.out.println(Arrays.toString(e));
        }

        System.out.println(r0729Sum(values));

        r0730(values);
        for(int[] e : values){
            System.out.println(Arrays.toString(e));
        }
    }

    public static void r0729FillWithZeroes(int[][] matrix){
        for (int i=0; i<matrix.length; i++){
            for (int j=0; j<matrix[0].length; j++){
                matrix[i][j] = 0;
            }
        }
    }

    public static void r0729FillAsCheckers(int[][] matrix){
        for (int i=0; i<matrix.length; i++){
            for (int j=0; j<matrix[0].length; j++){
                matrix[i][j] = (i%2 + j)%2;
            }
        }
    }

    public static void r0729TopBottomOnly(int[][] matrix){
        for (int j=0; j<matrix[0].length; j++){
            matrix[0][j] = 0;
            matrix[matrix.length-1][j] = 0;
        }
    }

    public static int r0729Sum(int[][] matrix){
        int result = 0;
        for (int i=0; i<matrix.length; i++){
            for (int j=0; j<matrix[0].length; j++){
                result += matrix[i][j];
            }
        }
        return result;
    }

    public static void r0730(int[][] matrix){
        for (int i=0; i<matrix.length; i++){
            for (int j=0; j<matrix[0].length; j++){
                if (i == 0 || j == 0 || i == matrix.length-1 || j == matrix[0].length-1) matrix[i][j] = 1;
            }
        }
    }

    public static void r0733(){
        ArrayList<String> a = new ArrayList<>();
        a.add("a");
        a.add("z");

        ArrayList<String> b;
        a.clone();
        System.out.println(a);
    }

    public static void e0701(){
        int[] arr = new int[10];
        Random r = new Random();
        for (int i=0; i<10; i++) arr[i] = r.nextInt(1, 100);

        for (int i=0; i<arr.length; i++){
            if (i%2 == 0) System.out.printf("%d ", arr[i]);
        }
        System.out.println();

        for (int e: arr){
            if (e%2 == 0) System.out.printf("%d ", e);
        }
        System.out.println();

        for (int i=arr.length-1; i>=0; i--){
            System.out.printf("%d ", arr[i]);
        }
        System.out.println();

        System.out.printf("%d %d\n", arr[0], arr[arr.length-1]);
        System.out.println();
    }

    public static void main(String[] args){
        e0701();
    }
}