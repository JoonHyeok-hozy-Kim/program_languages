// The JavaScript method is an object property that has a function value.
const person = {
    name: 'John',
    greet: function() { console.log("hi") }
};


// Accessing Object Methods
person.greet();              // Accessing the method
console.log(person.greet);   // Function Definition


// JavaScript Built-In Methods
let number = '11.3';
let result = parseInt(number);  // built-in method, parseInt()
console.log(number + " : " + typeof number + ", " + result  + " : " + typeof result);


// Adding a Method to a JavaScript Object
let student = {};
student.name = "AJ";
student.greet = function() { console.log("'s up?") }
student.greet();


// this Keyword
student.introduce = function() { console.log("My name is " + this.name) }
student.introduce();