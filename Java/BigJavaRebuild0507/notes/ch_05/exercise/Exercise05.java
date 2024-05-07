package exercise;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Map.Entry;
import java.util.Scanner;

public class Exercise05{
    public static void r0519(){        
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the score: ");
        int score = scanner.nextInt();
        char grade;

        if (score >= 90) {
            grade = 'A';
        } else if (score >= 80) {
            grade = 'B';
        } else if (score >= 70) {
            grade = 'C';
        } else if (score >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        System.out.println("Grade : " + grade);
    }

    public static void e0501(){
        Scanner in = new Scanner(System.in);
        System.out.print("Input a number: ");
        int n = in.nextInt();
        String s;
        if (n > 0){
            s = "positive";
        } else if (n < 0){
            s = "negative";
        } else {
            s = "zero";
        }
        System.out.println(s);
    }

    public static void e0502(){
        Scanner in = new Scanner(System.in);
        System.out.print("Input a number: ");
        double n = in.nextDouble();
        String s;
        if (n == 0){
            s = "zero";
        } else{
            if (n < 0){
                s = "negative";
            } else {
                s = "positive";
            }

            if (Math.abs(n) < 1){
                s += " small";
            } else if (Math.abs(n) > 1000000){
                s += " large";
            }
        }
        System.out.println(s);
    }

    public static void e0503(){
        Scanner in = new Scanner(System.in);
        System.out.print("Input a number: ");
        int n = in.nextInt();
        int result = 0;

        if (n < 0) n *= -1;

        while (n != 0){
            result += 1;
            n /= 10;
        }
        System.out.println(result);
    }

    public static void e0504(){
        Scanner in = new Scanner(System.in);
        int[] A = new int[3];
        System.out.print("Input the first number: ");
        A[0] = in.nextInt();
        System.out.print("Input the second number: ");
        A[1] = in.nextInt();
        System.out.print("Input the third number: ");
        A[2] = in.nextInt();

        if (A[0] == A[1]){
            if (A[1] == A[2]){
                System.out.println("all the same");
            } else {
                System.out.println("neither");
            }
        } else {
            if (A[1] != A[2]){
                if (A[0] != A[2]){
                    System.out.println("all different");
                } else {
                    System.out.println("neither");
                }
            } else {
                System.out.println("neither");
            }
        }
    }

    public static void e0505(){
        Scanner in = new Scanner(System.in);
        int[] A = new int[3];
        System.out.print("Input the first number: ");
        A[0] = in.nextInt();
        System.out.print("Input the second number: ");
        A[1] = in.nextInt();
        System.out.print("Input the third number: ");
        A[2] = in.nextInt();

        if (A[0] < A[1]){
            if (A[1] < A[2]){
                System.out.println("increasing");
            } else {
                System.out.println("neither");
            }
        } else if (A[0] > A[1]){
            if (A[1] > A[2]){
                System.out.println("decreasing");
            } else {
                System.out.println("neither");
            }
        } else {
            System.out.println("neither");
        }
    }

    public static void e0506(){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter 0 if you want the lenient mode: ");
        if (in.nextInt() != 0) {
            System.out.println("Strict Mode");
            e0505();
            return;
        }
        
        System.out.println("Lenient Mode");
        int[] A = new int[3];
        System.out.print("Input the first number: ");
        A[0] = in.nextInt();
        System.out.print("Input the second number: ");
        A[1] = in.nextInt();
        System.out.print("Input the third number: ");
        A[2] = in.nextInt();

        if (A[0] == A[1]){
            if (A[1] == A[2]){
                System.out.println("increasing/decreasing");
            } else if (A[1] > A[2]){
                System.out.println("decreasing");
            } else {
                System.out.println("increasing");
            }
        } else if (A[0] > A[1]){
            if (A[1] >= A[2]){
                System.out.println("decreasing");
            } else {
                System.out.println("neither");
            }
        } else {
            if (A[1] <= A[2]){
                System.out.println("increasing");
            } else {
                System.out.println("neither");
            }
        }
    }

    public static void e0507(){
        Scanner in = new Scanner(System.in);
        int[] A = new int[3];
        System.out.print("Input the first number: ");
        A[0] = in.nextInt();
        System.out.print("Input the second number: ");
        A[1] = in.nextInt();
        System.out.print("Input the third number: ");
        A[2] = in.nextInt();

        int t1 = A[0] - A[1];
        int t2 = A[1] - A[2];

        if (t1 * t2 < 0) {
            System.out.println("not in order");
        } else {
            System.out.println("in order");
        }
    }

    public static void e0508(){
        HashMap<Integer, Integer> h = new HashMap<>();
        Scanner in = new Scanner(System.in);
        int curr;
        for (int i=0; i<4; i++){
            System.out.printf("Input the number %d: ", i+1);
            curr = in.nextInt();
            if (h.containsKey(curr)){
                h.replace(curr, h.get(curr)+1);
            } else {
                h.put(curr, 1);
            }
        }

        int cnt = 0;
        Iterator<Entry<Integer, Integer>> entries = h.entrySet().iterator();
        while (entries.hasNext()){
            Map.Entry<Integer, Integer> entry = entries.next();
            if (entry.getValue() == 2){
                cnt += 1;
            }
        }
        if (cnt == 2){
            System.out.println("two pairs");
        } else {
            System.out.println("not two pairs");
        }
    }

    public static void e0509(){
        Scanner in = new Scanner(System.in);
        System.out.print("Input the clockwise degree from North: ");
        double degree = in.nextDouble();

        while (degree < 0) degree += 360;
        while (degree > 360) degree -= 360;

        int temp = 0;
        while (degree > 90) {
            temp += 100;
            degree -= 90;
        }
        if (degree > 45) {
            temp += 10;
            degree -= 45;
        }

        if (degree > 22.5){
            temp += 1;
        }

        if (temp == 0 || temp == 311){
            System.out.println("N");
        } else if (temp == 11 || temp == 100){
            System.out.println("E");
        } else if (temp == 111 || temp == 200){
            System.out.println("S");
        } else if (temp == 211 || temp == 300){
            System.out.println("W");
        } else{
            if (temp == 1 || temp == 10){
                System.out.println("NE");
            } else if (temp == 101 || temp == 110){
                System.out.println("SE");
            } else if (temp == 201 || temp == 210){
                System.out.println("SW");
            } else if (temp == 301 || temp == 310){
                System.out.println("NW");
            }
        } 
    }

    public static void e0510(){
        Scanner in = new Scanner(System.in);
        System.out.print("Employee Name: ");
        String name = in.nextLine();
        System.out.print("Hourly Wage: ");
        double salary = in.nextDouble();
        System.out.print("Hours worked: ");
        double work = in.nextDouble();

        double pay = salary * work;
        if (work > 40){
            pay += (work-40) * salary * 0.5;
        }

        PayCheck(name, pay);
    }

    public static void PayCheck(String name, double pay){
        System.out.println("----------------------");
        System.out.printf("Name %s\n", name);
        System.out.printf("Payment %.2f\n", pay);
        System.out.println("----------------------");
    }

    public static void e0511(){
        e0511Sub(0);
    }

    public static void e0511Sub(double altitude){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the temperature: ");
        double temperature = in.nextDouble();
        String type = "";
        while (!(type.equals("C") || type.equals("F"))){
            System.out.print("Enter C for Celsius / F for Fahrenheit: ");
            type = in.nextLine();
            if (type.equals("C")){
                System.out.println("Celsius selected.");
            } else if (type.equals("F")){
                System.out.println("Fahrenheit selected.");
            } else{
                System.out.println("Invalid value");
            }
        }
        
        if (type.equals("F")){
            temperature -= 32;
            temperature /= 9/5;
        }

        double boil_point = 100 - altitude/300;
        String result;
        if (temperature < 0) {
            result = "Solid";
        } else if (temperature < boil_point ){
            result = "Liquid";
        } else {
            result = "Gaseous";
        }
        System.out.printf("\n%s", result);

    }

    public static void e0512(){
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the current altitude in meter(s): ");
        double altitude = in.nextInt();
        e0511Sub(altitude);
    }

    public static void e0514(){
        Time05 t1 = new Time05(13, 50);
        Time05 t2 = new Time05(20, 40);
        Time05 t3 = new Time05(20, 40);
        Time05 t4 = new Time05(20, 50);

        System.out.println(t1.compareTo(t2));
        System.out.println(t2.compareTo(t1));
        System.out.println(t2.compareTo(t3));
        System.out.println(t2.compareTo(t3));
    }

    public static void e0515(){
        Date05 d1 = new Date05(2, 1);
        d1.getSeason();

        Date05 d2 = new Date05(3, 10);
        d2.getSeason();

        Date05 d3 = new Date05(3, 30);
        d3.getSeason();
    }

    public static void e0516(){
        char a = 'A';
        System.out.println((int)a);
    }

    public static void e0517(){
        Grade05 g1 = new Grade05();
        g1.getNumericGrade();
    }

    public static void e0518(){
        ArrayList<Double> incomes = new ArrayList<>();
        incomes.add(45000.0);
        incomes.add(51000.0);
        incomes.add(60000.0);
        incomes.add(75000.0);
        incomes.add(600000.0);

        for (int i=0; i<incomes.size(); i++){
            System.out.printf("%.2f -> %.2f\n", incomes.get(i), afterTaxIncome(incomes.get(i)));
        }
    }

    public static double afterTaxIncome(double income){
        ArrayList<Double> taxTable = new ArrayList<>();
        ArrayList<Double> taxRate = new ArrayList<>();
        
        taxTable.add(50000.0);
        taxTable.add(25000.0);
        taxTable.add(25000.0);
        taxTable.add(150000.0);
        taxTable.add(250000.0);
        taxTable.add(Double.MAX_VALUE);

        for (int i=0; i<6; i++){
            taxRate.add((double) (i+1));
        }

        double copy = income;
        double afterTaxIncome = 0;
        for (int i=0; i<taxTable.size(); i++){
            if (copy > 0){
                afterTaxIncome += Math.min(copy, taxTable.get(i)) * (1-taxRate.get(i)/100);
                copy -= taxTable.get(i);
            }
        }

        return afterTaxIncome;
    }

    public static void e0520(){
        Scanner in = new Scanner(System.in);
        double curr = Double.MIN_VALUE;
        for (int i=0; i<3; i++){
            System.out.printf("Enter the number %d: ", i+1);
            curr = Math.max(curr, in.nextDouble());
        }
        System.out.printf("The largest number is %f\n", curr);
    }

    public static void e0521(){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter three strings: ");
        String[] s = in.nextLine().split(" ");

        PriorityQueue<String> pq = new PriorityQueue<>(1, new StringComparator());
        
        for (int i=0; i<s.length; i++){
            pq.add(s[i]);
        }

        while (!pq.isEmpty()){
            System.out.println(pq.poll());
        }
    }

    public static void p0505() {
        rectangleSpecifier(new Point(0,0), new Point(4,4));
    }

    public static void rectangleSpecifier(Point p1, Point p2){
        double width = Math.abs(p1.getX() - p2.getX());
        double height = Math.abs(p1.getY() - p2.getY());
        String result;
        if (width == height){
            result = "Square";
        } else if (width > height){
            result = "Landscape";
        } else {
            result = "Portrait";
        }
        System.out.println(result);
    }


    public static void main(String[] args){
        p0505();
    }

}

class StringComparator implements Comparator<String>{
@Override
public int compare(String s1, String s2){
    return s1.compareTo(s2);
}

class Point{
    double x;
    double y;

    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }
}


}