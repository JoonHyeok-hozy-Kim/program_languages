// Object Declaration
const student = {
    name: 'John',
    age: 10
};
console.log(typeof student);    // Object


// Object Declaration single line
const teacher = { name: 'Paul', age: 20};
console.log(typeof teacher);  


// Object Properties : In JavaScript, "key: value" pairs are called properties.
// Accessing the properties
console.log(student.name);
console.log(student["age"]);



// Nested Objects
const obj1 = {
    prop1: 100,
    obj2: {
        prop2: 200,
        prop3: 300
    }
};
console.log(obj1.prop1);
console.log(obj1.obj2.prop2);


// Object Methods
const person = {
    name: "Sam",
    age: 30,
    // Use function as a value
    greet: function() { console.log('hello') }
}
person.greet();