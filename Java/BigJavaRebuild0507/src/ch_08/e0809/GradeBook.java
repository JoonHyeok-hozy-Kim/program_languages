package ch_08.e0809;

import java.util.ArrayList;
import java.util.Scanner;

public class GradeBook {
    private ArrayList<Student> students = new ArrayList<>();

    public GradeBook(){
        getStudents();
    }

    public void getStudents(){
        Scanner in = new Scanner(System.in);
        String tempInput;
        String escaper = "x";
        while (true){
            System.out.print("Enter the name (Enter " + escaper + " to exit): ");
            tempInput = in.nextLine();
            if (tempInput.equals(escaper)) break;
            Student currStudent = new Student(tempInput);
            this.students.add(currStudent);
        }
        
        for (Student s: this.students){
            s.getScores();
        }
    }

    public void displayScores(){
        for (Student s : this.students){
            System.out.println(s.showInfo());
        }
    }
}
