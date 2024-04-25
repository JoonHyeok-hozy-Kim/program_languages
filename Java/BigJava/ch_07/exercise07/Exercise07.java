package exercise07;

import java.lang.reflect.Array;
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

    public static int sumWithoutSmallest(int[] arr){
        int sum = arr[0];
        int smallest = arr[0];

        for (int i=1; i<arr.length; i++){
            sum += arr[i];
            smallest = Math.min(smallest, arr[i]);
        }

        return sum - smallest;
    }

    public static void e0703(){
        int[] a = {1,2,3,4,5};
        System.out.println(sumWithoutSmallest(a));
    }

    public static int alteringSum(int[] arr){
        int sum = 0;
        for (int i=0; i<arr.length; i++){
            sum += arr[i] * ((((i+1)%2) * 2) - 1);
            /*if (i%2 == 0) sum += arr[i];
            else sum -= arr[i];*/
        }
        return sum;
    }

    public static void e0705(){
        int[] a = {1, 4, 9, 16, 9, 7, 4, 9, 11};
        System.out.println(alteringSum(a));
    }

    public static void arrayReverse(int[] arr){
        int temp;
        for (int i=0; i<arr.length/2; i++){
            temp = arr[i];
            arr[i] = arr[arr.length-1-i];
            arr[arr.length-1-i] = temp;
        }
    }

    public static void e0706(){
        int[] a = {1, 4, 9, 16, 9, 7, 4, 9, 11};
        arrayReverse(a);
        System.out.println(Arrays.toString(a));
    }

    public static int[] randomPermutationOneToTen(){
        int[] result = new int[10];
        ArrayList<Integer> pocket = new ArrayList<>();
        Random r = new Random();
        for (int i=1; i<=10; i++) pocket.add(i);

        int idx = 0;
        int jdx;
        while (! pocket.isEmpty()){
            jdx = r.nextInt(0, pocket.size());
            result[idx] = pocket.get(jdx);
            pocket.remove(jdx);
            idx++;
        }
        return result;
    }

    public static void e0707(){
        for (int i=0; i<5;i ++){
            System.out.println(Arrays.toString(randomPermutationOneToTen()));
        }
    }

    public static class DataSetEx07 {
        private int maximumNumberOfValues;
        private double[] data;
        private int currIdx=0;
    
        public DataSetEx07(int maximumNumberOfValues){
            this.maximumNumberOfValues = maximumNumberOfValues;
            this.data = new double[this.maximumNumberOfValues];
        }
    
        public void add(double value){
            if (this.currIdx < this.maximumNumberOfValues){
                this.data[this.currIdx] = value;
                this.currIdx++;
            }
        }

        public double sum(){
            double result = 0;
            for (int i=0; i<this.currIdx; i++){
                result += this.data[i];
            }
            return result;
        }

        public double average(){
            return this.sum() / this.currIdx;
        }

        public double maximum(){
            double result = this.data[0];
            for (int i=1; i<this.currIdx; i++) {
                if (this.data[i] > result) result = this.data[i];
            }
            return result;
        }

        public double minimum(){
            double result = this.data[0];
            for (int i=1; i<this.currIdx; i++) {
                if (this.data[i] < result) result = this.data[i];
            }
            return result;
        }
    }

    public static void e0708(){
        DataSetEx07 dt = new DataSetEx07(20);
        for (int i=0; i<10; i++){
            dt.add(i+1);
            
        }
        System.out.println(dt.sum());
        System.out.println(dt.average());
        System.out.println(dt.maximum());
        System.out.println(dt.minimum());
    }

    public static class ArrayMethods{
        private int[] values;
        
        public ArrayMethods(int[] initialValues) {this.values = initialValues;}

        public void printArray() {
            System.out.println(Arrays.toString(this.values));
        }

        public void swapFirstAndLast(){
            int temp = this.values[0];
            this.values[0] = this.values[this.values.length-1];
            this.values[this.values.length-1] = temp;
            this.printArray();
        }

        public void shiftRight(){
            int temp = this.values[this.values.length-1];
            for (int i=this.values.length-1; i>=1; i--) this.values[i] = this.values[i-1];
            this.values[0] = temp;
            this.printArray();
        }

        public void replaceEvenToZero(){
            for (int i=0; i<this.values.length; i++){
                if (this.values[i] % 2 == 0) this.values[i] = 0;
            }
            this.printArray();
        }

        public void replaceWithLargerNeighbor(){
            int[] modified = new int[this.values.length];
            modified[0] = this.values[0];
            modified[this.values.length-1] = this.values[this.values.length-1];

            for (int i=1; i<this.values.length-1; i++){
                modified[i] = Math.max(this.values[i], Math.max(this.values[i-1], this.values[i+1]));
            }
            this.values = modified;
            this.printArray();
        }

        public void removeMiddle() {
            int new_size = this.values.length - 1;
            if (this.values.length % 2 == 0) new_size -= 1;
            int[] new_array = new int[new_size];
            int idx = 0;
            for (int i=0; i<this.values.length; i++){
                if (this.values.length/2 == i || (this.values.length % 2 == 0 && this.values.length/2 == i+1)) continue;
                new_array[idx] = this.values[i];
                idx++;
            }
            this.values = new_array;
            this.printArray();
        }

        // 0 1 2 3 4 5  : 6
        //     v v      : 2, 3
        // 0 1 2 3 4    : 5
        //     v        : 2

        public void moveEvensFront(){
            int[] temp_arr = new int[this.values.length];
            int idx = 0;
            for (int i=0; i<this.values.length; i++){
                if (this.values[i] %2 == 0){
                    temp_arr[idx] = this.values[i];
                    this.values[i] = 0;
                    idx++;
                }
            }
            for (int i=0; i<this.values.length; i++){
                if (this.values[i] %2 != 0){
                    temp_arr[idx] = this.values[i];
                    idx++;
                }
            }
            this.values = temp_arr;
            this.printArray();
        }

        public int secondLargestElement(){
            int n1 = Math.max(this.values[0], this.values[1]);
            int n2 = Math.min(this.values[0], this.values[1]);

            for (int e : this.values){
                if (e > n1){
                    n2 = n1;
                    n1 = e;
                } else if (e > n2){
                    n2 = e;
                }
            }
            return n2;
        }

        public boolean isSorted(){
            int curr = this.values[0];
            for (int e: this.values){
                if (curr > e) return false;
                curr = e;
            }
            return true;
        }

        public boolean adjacentDuplicate() {
            if (this.values.length <= 1) return false;
            int n1;
            int n2;

            for (int i=1; i<this.values.length; i++){
                if (this.values[i-1] == this.values[i]) return true;
            }
            return false;
        }

        public boolean containsDuplicate(){
            for (int i=0; i<this.values.length; i++){
                for (int j=i+1; j<this.values.length; j++){
                    if (this.values[i] == this.values[j]) return true;
                }
            }
            return false;
        }
    }

    public static void e0710(){
        int[] arr = {1, 4, 9 ,16, 25};
        ArrayMethods a = new ArrayMethods(arr);
        // a.printArray();
        // a.swapFirstAndLast();
        // a.shiftRight();
        // a.replaceEvenToZero();
        // a.replaceWithLargerNeighbor();
        // a.removeMiddle();
        // a.removeMiddle();
        // a.moveEvensFront();
        // a.secondLargestElement();
        // System.out.println(a.secondLargestElement());
        // System.out.println(a.isSorted());
        // a.moveEvensFront();
        // System.out.println(a.isSorted());

        System.out.println(a.adjacentDuplicate());
        int[] brr = {1,2,3,3,4,5};
        ArrayMethods b = new ArrayMethods(brr);
        System.out.println(b.adjacentDuplicate());

        
        int[] crr = {1,2,3,4,3,5};
        ArrayMethods c = new ArrayMethods(crr);
        System.out.println(a.containsDuplicate());
        System.out.println(b.containsDuplicate());
        System.out.println(c.containsDuplicate());
    }

    public static class Sequence
    {
        private int[] values;
        public Sequence(int size) { values = new int[size]; }
        public Sequence(String s, String delimiter) {
            String[] ss = s.split(delimiter);
            this.values = new int[ss.length];
            for (int i=0; i<ss.length; i++){
                this.set(i, Integer.valueOf(ss[i]));
            }
        }
        public void set(int i, int n) { values[i] = n; }
        public int get(int i) { return values[i]; }
        public int size() { return values.length; }

        public boolean equals(Sequence other){
            if (this.size() != other.size()) return false;

            for (int i=0; i<this.size(); i++){
                if (this.get(i) != other.get(i)) return false;
            }
            return true;
        }

        public boolean sameValues(Sequence other){
            int[] copy = new int[Math.max(this.size(), other.size())];
            int copiedCnt = 0;
            boolean pass;
            boolean found;
            for (int i=0; i<this.size(); i++){
                pass = false;
                for (int j=0; j<copiedCnt; j++){
                    if (this.get(i) == copy[j]){
                        pass = true;
                        break;
                    }
                }
                if (pass) continue;
                copy[copiedCnt] = this.get(i);
                copiedCnt++;
            }
            // System.out.println(Arrays.toString(copy));

            for (int i=0; i<other.size(); i++){
                found = false;
                for (int j=0; j<copiedCnt; j++){
                    if (other.get(i) == copy[j]){
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
            return true;
        }

        public boolean isPermutationOf(Sequence other){
            ArrayList<Integer> thisCopy = new ArrayList<>();
            for (int i=0; i<this.size(); i++){
                thisCopy.add(this.get(i));
            }
            for (int j=0; j<other.size(); j++){
                if (thisCopy.isEmpty()) return false;
                if (!thisCopy.contains(other.get(j))) return false;
                thisCopy.remove(thisCopy.indexOf(other.get(j)));
            }
            if (thisCopy.isEmpty()) return true;
            return false;
        }

        public void printValues(){
            for (int i=0; i<this.size(); i++){
                System.out.printf("%d ", this.get(i));
            }
            System.out.println();
        }

        public Sequence sum(Sequence other){
            int maxLength = Math.max(this.size(), other.size());
            Sequence result = new Sequence(maxLength);
            int tempSum;
            for (int i=0; i<maxLength; i++){
                tempSum = 0;
                if (i < this.size()) tempSum += this.get(i);
                if (i < other.size()) tempSum += other.get(i);
                result.set(i, tempSum);
            }
            return result;
        }

        public void sortValues(){
            int[] copied = new int[this.size()];
            for (int i=0; i<this.size(); i++) copied[i] = this.get(i);
            Arrays.sort(copied);
            for (int i=0; i<this.size(); i++) this.set(i, copied[i]);
        }
    }

    public static void e0711(){
        Sequence[] s = new Sequence[4];
        s[0] = new Sequence(3);
        for (int i=0; i<s[0].size(); i++){
            s[0].set(i, i);
        }
        s[1] = new Sequence(1);
        for (int i=0; i<s[1].size(); i++){
            s[1].set(i, i);
        }
        System.out.println(s[0].equals(s[1]));
        s[2] = new Sequence(3);
        for (int i=0; i<s[2].size(); i++){
            s[2].set(i, i+1);
        }
        System.out.println(s[0].equals(s[2]));
        s[3] = new Sequence(3);
        for (int i=0; i<s[3].size(); i++){
            s[3].set(i, i);
        }
        System.out.println(s[0].equals(s[3]));
    }

    public static void e0712(){
        Sequence s1 = new Sequence(9);
        Sequence s2 = new Sequence(7);

        String str1 = "1 4 9 16 9 7 4 9 11";
        String str2 = "11 11 7 9 16 4 1";

        int idx = 0;
        for (String s: str1.split(" ")){
            s1.set(idx, Integer.valueOf(s));
            idx++;
        }
        idx = 0;
        for (String s: str2.split(" ")){
            s2.set(idx, Integer.valueOf(s));
            idx++;
        }

        System.out.println(s1.sameValues(s2));
    }

    public static void e0713(){
        String[] S = {
            "1 4 9 16 9 7 4 9 11",
            "11 1 4 9 16 9 7 4 9",
            "11 11 7 9 16 4 1 4 9"
        };

        Sequence[] SQ = new Sequence[S.length];
        for (int i=0; i<S.length; i++){
            SQ[i] = new Sequence(S[i], " ");
            SQ[i].printValues();
        }

        System.out.println(SQ[0].isPermutationOf(SQ[1]));
        System.out.println(SQ[0].isPermutationOf(SQ[2]));
    }

    public static void e0714(){
        Sequence s1 = new Sequence("1 4 9 16 9 7 4 9 11", " ");
        Sequence s2 = new Sequence("11 11 7 9 16 4 1", " ");

        s1.sum(s2).printValues();
    }

    public static void e0715(){
        Sequence s2 = new Sequence("11 11 7 9 16 4 1", " ");
        s2.printValues();
        s2.sortValues();
        s2.printValues();
    }


    public static class Table
    {
        private int[][] values;
        public Table(int rows, int columns) { values = new int[rows][columns]; }
        public void set(int i, int j, int n) { values[i][j] = n; }
        public int get(int i, int j) { return this.values[i][j]; }

        private boolean validateIndex(int i, int j){
            if (i < 0 || i >= this.values.length) return false;
            if (j < 0 || j >= this.values[0].length) return false;
            return true;
        }

        private ArrayList<Integer> getNeighbors(int row, int column){
            int[][] directions = {
                {-1, -1}, {-1, 0}, {-1, 1},
                {0, -1}, {0, 0}, {0, 1},
                {1, -1}, {1, 0}, {1, 1},
            };

            ArrayList<Integer> result = new ArrayList<>();
            for (int[] dir: directions){
                if (!validateIndex(dir[0]+row, dir[1]+column)) continue;
                result.add(this.get(dir[0]+row, dir[1]+column));
            }

            return result;
        }

        public double neighborAverage(int row, int column){
            double result = 0;
            ArrayList<Integer> neighbors = getNeighbors(row, column);

            if (neighbors.isEmpty()) return 0;
            for (int v: neighbors){
                result += v;
            }
            return result / neighbors.size();
        }

        public double sum(int i, boolean horizontal){
            double result = 0;
            if (horizontal){
                while (i < 0) i += this.values.length;
                for (int j=0; j<this.values[0].length; j++){
                    result += this.get(i, j);
                }
            } else {
                while (i < 0) i += this.values[0].length;
                for (int j=0; j<this.values.length; j++){
                    result += this.get(j, i);
                }
            }
            return result;
        }
    }

    public static void e0716(){
        int rowNum = 10;
        int colNum = 10;
        Table t = new Table(rowNum, colNum);
        int cnt = 1;
        for (int i=0; i<rowNum; i++){
            for (int j=0; j<colNum; j++){
                t.set(i, j, cnt++);
            }
        }
        for (int i=0; i<rowNum; i++){
            for (int j=0; j<colNum; j++){
                System.out.printf("%d ", t.get(i, j));
            }
            System.out.println();
        }
        System.out.println(t.neighborAverage(8, 8));
        System.out.println(t.neighborAverage(0, 0));

        System.out.println(t.sum(0, true));
        System.out.println(t.sum(0, false));
    }

    public static class AsteriskBarChart{
        private ArrayList<Integer> values = new ArrayList<>();
        private int maxVal = -1;
        final private int horizontalMax = 40;
        final private int verticalMax = 20;

        public AsteriskBarChart(){
            Scanner scanner = new Scanner(System.in);
            int curr;
            while (true){
                System.out.print("Enter an integer value: ");
                if (! scanner.hasNextInt()) break;
                curr = scanner.nextInt();
                values.add(curr);
                maxVal = Math.max(maxVal, curr);
            }
        }

        public void drawBarChart(){
            if (this.values.isEmpty()) return;
            for (int v: this.values){
                // System.out.println((int) (v * 40 / maxVal));
                for (int i=0; i<v * horizontalMax / maxVal; i++){
                    System.out.print("*");
                }
                System.out.println();
            }
        }

        public void drawVerticalBarChart(){
            if (this.values.isEmpty()) return;
            int[] blanks = new int[this.values.size()];

            for (int j=verticalMax; j>0; j--){
                for (int i=0; i<this.values.size(); i++){
                    if (j <= this.values.get(i) * verticalMax / this.maxVal) System.out.print("*");
                    else System.out.print(" ");
                }
                System.out.println();
            }

        }
    }

    public static void e0718(){
        AsteriskBarChart a = new AsteriskBarChart();
        //a.drawBarChart();
        a.drawVerticalBarChart();
    }

    public static void e0720(){        
        int rowNum = 3;
        int colNum = 3;
        Table t = new Table(rowNum, colNum);
        int cnt = 1;
        for (int i=0; i<rowNum; i++){
            for (int j=0; j<colNum; j++){
                t.set(i, j, cnt++);
            }
        }
        for (int i=0; i<rowNum; i++){
            for (int j=0; j<colNum; j++){
                System.out.printf("%d ", t.get(i, j));
            }
            System.out.println();
        }

        System.out.println(t.sum(-1, true));
        System.out.println(t.sum(-1, false));
    }

    public static class ALSequence
    {
        private ArrayList<Integer> values;
        public ALSequence() { values = new ArrayList<Integer>(); }
        public ALSequence(String S, String delimiter) { 
            values = new ArrayList<Integer>();
            for (String s: S.split(" ")){
                values.add(Integer.valueOf(s));
            }
        }
        public void add(int n) { values.add(n); }
        public String toString() { return values.toString(); }
        public void printALSequence() { System.out.println(this.toString()); }

        public ALSequence append(ALSequence other){            
            ALSequence result = new ALSequence();
            for (int e: this.values){
                result.add(e);
            }
            for (int f: other.values){
                result.add(f);
            }
            return result;
        }

        public ALSequence merge(ALSequence other){
            ALSequence result = new ALSequence();
            int i = 0;
            int j = 0;

            while (i < this.values.size() || j < this.values.size()){
                if (j == this.values.size() || (i+j)%2 == 0) {
                    result.add(this.values.get(i++));
                } else {
                    result.add(other.values.get(j++));
                }
            }
            return result;
        }

        public ALSequence mergeSorted(ALSequence other){
            ALSequence result = new ALSequence();
            int i = 0;
            int j = 0;
            while (i + j < this.values.size() + other.values.size()){
                if (j == other.values.size() || (i < this.values.size() && this.values.get(i) < other.values.get(j))){
                    result.add(this.values.get(i++));
                } else {
                    result.add(other.values.get(j++));
                }
            }
            return result;
        }
    }

    public static void e0722(){
        ALSequence a = new ALSequence("1 4 9 16", " ");
        ALSequence b = new ALSequence("9 7 4 9 11", " ");
        a.append(b).printALSequence();
        a.merge(b).printALSequence();

        ALSequence c = new ALSequence("4 7 9 9 11", " ");
        a.mergeSorted(c).printALSequence();
    }


    public static void main(String[] args){
        e0722();
    }
}