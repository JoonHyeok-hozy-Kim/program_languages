package ch_09.objects.Person;

public class Person {
    private String name;
    private int yearOfBirth;

    public Person(String name, int yearOfBirth){
        this.name = name;
        this.yearOfBirth = yearOfBirth;
    }

    public String toString(){
        String result = this.getClass().getName();
        result += "\n - Name : " + this.name;
        result += "\n - Year of Birth : " + this.yearOfBirth;
        return result;
    }
}
