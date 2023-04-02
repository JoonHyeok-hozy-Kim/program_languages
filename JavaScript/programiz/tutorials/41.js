/** Classes are one of the features introduced in the ES6 version of JavaScript.
 * A class is a blueprint for the object. You can create an object from the class.
 * You can think of the class as a sketch (prototype) of a house. It contains all the details about the floors, doors, windows, etc. Based on these descriptions, you build the house. House is the object.
 * Since many houses can be made from the same description, we can create many objects from a class. 
*/


// Creating JavaScript Class
class Person {
    // Constructor
    constructor(name) {
        this.name = name;
    }

    // Method
    greet() {
        console.log(`Hi, I'm ${this.name}`);
    }


    // Getter
    get personName() {
        return this.name;
    }

    // Setter
    set personName(name){
        this.name = name;
    }
}


// Creating Objects out of the Class
const p1 = new Person('John');
const p2 = new Person('AJ');

// Method Test
p2.greet();

// Getter & Setter Test
console.log(p2.personName);
p2.personName = 'AJK';
p2.greet();




// No hoisting for Classes
// 'use strict'