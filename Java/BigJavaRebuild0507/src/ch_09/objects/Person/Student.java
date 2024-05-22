package ch_09.objects.Person;

public class Student extends Person {
    private String major;

    public Student(String name, int yearOfBirth){
        super(name, yearOfBirth);
    }

    public void setMajor(String major){
        this.major = major;
    }

    public String toString(){
        String result = super.toString();
        result += "\n - major : " + this.major;
        return result;
    }
}
