package exercise.r0801;

public class Person {
    private String name;
    static private int PERSONID = 1;
    private int personID;

    public Person(){
        this.personID = this.PERSONID++;
        System.out.printf("A Person created. (ID : %d)", this.personID);
    };

    public void sayHi(){
        System.out.println("Hi");
    }
}
