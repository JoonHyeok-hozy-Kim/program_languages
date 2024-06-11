package ch_10.exercises.RSeries;

import java.awt.Rectangle;

import ch_10.objects.Measurable.Measurable;
import ch_10.objects.Measurer.Measurer;

public class RSeries {
    public static void r1001(){
        int a = 2000000000;
        int b = -a;

        System.out.println(a);
        System.out.println(b);
        System.out.println(a-b);
        System.out.println(b-a);
        System.out.println(Integer.compare(a, b));
        System.out.println(Integer.compare(b, a));
    }

    public static void r1002(){
        double a = 0.6;
        double b = 0.3;
        
        System.out.println((int)(a-b));
        System.out.println((int)(b-a));
        System.out.println(Double.compare(a, b));
        System.out.println(Double.compare(b, a));
    }

    public static interface I{
        public void i1();
    }
    public static interface J{
        public void j1();
    }
    public static class C implements I, J {
        public C() {}
        public void i1(){}
        public void j1(){}
    }

    public static void r1003(){
        C c;
        I i = new C();
        J j;

        c = (C) i;
        j = c;
        i = (I) j;
    }

    public static void r1004(){
        I i = new C();

        C c = (C) i;
        J j = (J) i;
        i = (I) null;
    }

    public static interface Edible {}
    public static class Sandwich implements Edible{};

    public static void r1005(){
        Sandwich sub = new Sandwich();
        Rectangle cerealBox = new Rectangle(5, 10, 20, 30);
        Edible e = null;

        e = sub;
        // sub = e;
        sub = (Sandwich) e;
        // sub = (Sandwich) cerealBox;
        // e = cerealBox;
        e = (Edible) cerealBox;
        // e = (Rectangle) cerealBox;
        // e = (Rectangle) null;
    }

    public static class Employee1 implements Measurable{
        private String name;
        private double salary;

        public Employee1(String name, double salary){
            this.name = name;
            this.salary = salary;
        }

        public double getMeasure(){
            return this.salary;
        }
    }

    public static void r10091(){
        Employee1[] eList = new Employee1[5];
        for (int i=0; i<5; i++){
            eList[i] = new Employee1(String.valueOf(i), i+1);
        }

        double average = ch_10.objects.Measurable.Data.average(eList);
        System.out.println(average);
    }

    public static class Employee2 implements Measurable{
        private String name;
        private double salary;

        public Employee2(String name, double salary){
            this.name = name;
            this.salary = salary;
        }
    }

    public static class SalaryMeasurer implements Measurer{
        public double measure(Object object){
            Employee2 e = (Employee2) object;
            return e.salary;
        }
    }

    public static void r10092(){
        Employee2[] eList = new Employee2[5];
        for (int i=0; i<5; i++){
            eList[i] = new Employee2(String.valueOf(i), i+1);
        }

        double average = ch_10.objects.Measurer.Data.average(eList, new SalaryMeasurer());
        System.out.println(average);
    }

    public static void r1009(){
        r10091();
        r10092();
    }

    public static void r1010(){
        String[] S = {"a", "b", "c"};
        // double average = ch_10.objects.Measurable.Data.average(S);
    }

    public static class StringMeasurer implements Measurer{
        public double measure(Object object){
            String s = (String) object;
            return s.length();
        }
    }

    public static void r1011(){
        String[] S = {"a", "bbb", "cc"};
        double average = ch_10.objects.Measurer.Data.average(S, new StringMeasurer());
        System.out.println(average);
    }

    public static class T{
        private int t = 1;

        public void m(final int x, int y){
            int a = 2;
            final int b = 3;

            class C implements I{
                public void i1(){
                    System.out.println(t);
                    System.out.println(x);
                    System.out.println(y);
                    System.out.println(a);
                    System.out.println(b);
                    // System.out.println(c);
                }
            }

            final int c = 4;

            I ic = new C();
            ic.i1();
        }
    }

    public static void r1013(){
        T t = new T();
        t.m(11, 12);
    }

    public static void main(String[] args){
        r1013();
    }
    
}
