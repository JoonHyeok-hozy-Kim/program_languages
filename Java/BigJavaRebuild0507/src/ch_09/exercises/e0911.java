package ch_09.exercises;

import java.util.ArrayList;

import ch_09.objects.Person.*;

public class e0911 {
    public static void ToStringTester(Person p){
        System.out.println(p.toString());
    }

    public static void main(String[] args){
        Person p = new Person("abc", 12);
        Student s = new Student("def", 13);
        s.setMajor("Economics");
        Instructor i = new Instructor("ghi", 14);
        i.setSalary(1000);

        ToStringTester(p);
        ToStringTester(s);
        ToStringTester(i);
    }
}
