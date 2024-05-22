package ch_09.objects.Person;

public class Instructor extends Person {
    private double salary;

    public Instructor(String name, int yearOfBirth){
        super(name, yearOfBirth);
    }

    public void setSalary(double initialSalary){
        this.salary = initialSalary;
    }

    public String toString(){
        String result = super.toString();
        result += "\n - Salary : " + this.salary;
        return result;
    }
}
