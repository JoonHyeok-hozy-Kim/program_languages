package exercise;

import java.util.LinkedList;
import java.util.Scanner;

public class Grade05 {
    public String letterGrade = "";

    public Grade05(){
        Scanner in = new Scanner(System.in);
        String input;
        while (this.letterGrade == ""){
            System.out.print("Enter a letter grade: ");
            input = in.nextLine();
            if (input.length() > 2){
                continue;
            } else if (!(input.charAt(0) == 'A' ||input.charAt(0) == 'B' ||input.charAt(0) == 'C' || 
                        input.charAt(0) == 'D' ||input.charAt(0) == 'F')){
                continue;
            } else if (input.length() == 2 && !(input.charAt(1)=='+' || input.charAt(1)=='-')){
                continue;
            } else if (input.charAt(0) == 'F' && input.length() == 2){
                continue;
            }

            this.letterGrade = input;
        }
    }

    public void getNumericGrade(){
        double numericGrade = 69 - this.letterGrade.charAt(0);
        if (this.letterGrade.length() == 2){
            if (this.letterGrade.charAt(1) == '+'){
                if (this.letterGrade.charAt(0) != 'A'){
                    numericGrade += 0.3;
                }
            } else {
                numericGrade -= 0.3;
            }
        }

        System.out.printf("The numeric value is %.1f", numericGrade);
    }
}
