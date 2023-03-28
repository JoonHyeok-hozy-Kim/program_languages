// In JavaScript, every function and object has a property named prototype by default.
function Person() {
    this.name = "John",
    this.age = 23
};

const p1 = new Person();
console.log(Person.prototype);



/* Prototype Inheritance
In JavaScript, a prototype can be used to add properties and methods to a constructor function. 
And objects inherit properties and methods from a prototype.
*/
const p2 = new Person();
Person.prototype.gender = 'Male';
console.log(Person.prototype);
console.log(p1.gender);
console.log(p2.gender);


// Add Methods to a Constructor Function Using Prototype
Person.prototype.greet = function() {
    console.log("Hi, I'm " + this.name);
}
p1.greet();
p2.greet();


// Changing Prototype : Only the "new" objects will have the changed property value
Person.prototype = { gender: "Female" };
const p3 = new Person()
console.log(p1.gender);
console.log(p3.gender);


/* Prototype Chaining
If an object tries to access the same property that is in the constructor function and the prototype object, 
the object takes the property from the constructor function.
*/
Person.prototype.name = "Daniel";
console.log(p1.name);   // Still John!



// Accessing prototype property
console.log(p1.__proto__);