/**Inheritance enables you to define a class that takes all the functionality from a parent class and allows you to add more.
 * Using class inheritance, a class can inherit all the methods and properties of another class.
 */

class Person {
    constructor(name) {
        this.name = name;
    }

    greet() {
        console.log(`Hello, I'm ${this.name}`);
    }
};

class Student extends Person {
    constructor(name, id) {
        super(name);    // constructor for the parent Person
        this.id = id;
    }

    // Method Overriding
    greet() {
        console.log(`Hello, I'm ${this.name} (ID : ${this.id})`);
    }


};

let p1 = new Person('AJ');
p1.greet();
let s1 = new Student('Hozy', 123);
s1.greet();

