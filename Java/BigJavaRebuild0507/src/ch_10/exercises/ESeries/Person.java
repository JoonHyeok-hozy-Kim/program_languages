package ch_10.exercises.ESeries;

import ch_10.objects.Measurable.Measurable;

public class Person implements Measurable {
    private String name;
    private double height;

    public Person(String name, double height){
        this.name = name;
        this.height = height;
    }

    public String toString(){
        return "(" + this.name + " / " + this.height + ")";
    }

    public double getMeasure(){
        return this.height;
    }
}
