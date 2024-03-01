package exercise;

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
        Scanner s = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n = s.nextInt();
        String message;

        if (n > 0){
            message = "Positive";
        } else if (n < 0){
            message = "Negative";
        } else {
            message = "Zero";
        }

        System.out.println(message);
    }

    public static void e0502(){
        Scanner s = new Scanner(System.in);
        System.out.print("Enter a number: ");
        double n = s.nextDouble();
        String m1;

        if (n > 0){
            m1 = "Positive";
        } else if (n < 0){
            m1 = "Negative";
        } else {
            m1 = "Zero";
        }

        System.out.println(m1);

        if (Math.abs(n) < 1){
            System.out.println("Small");
        } else if (Math.abs(n) > 1000000){
            System.out.println("Large");
        }

    }

    public static void e0503(){
        System.out.println(-5/10);
        System.out.println(-20/10);
    }

    public static int digitCounter(int n){
        int result = 0;
        int unit = 1;
        if (n < 0) unit *= -1;

        while (n != 0) {
            result += 1;
            n /= 10;
        }

        return result;
    }

    public static void main(String[] args){
        e0503();
    }
}