package Java.BigJava.ch_04.sub_05;

import java.util.Scanner;

public class Initials {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter your first name : ");
        String first = in.next();
        
        System.out.println("Enter your last name : ");
        String last = in.next();

        System.out.println(first.substring(0,1)+"&"+last.substring(0,1));
    }
}
