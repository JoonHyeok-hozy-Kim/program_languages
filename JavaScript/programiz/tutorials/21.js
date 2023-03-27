// Constructor Function
function Person() {
    this.name = "AJ",
    this.age = "28"
};

const p1 = new Person();    
const p2 = new Person();    
console.log(p1.name);
console.log(p2.name);


// Constructor Function Parameters
function Person(name, age, gender){
    this.name = name,
    this.age = age,
    this.gender = gender,
    this.greet = function() {
        return ( "Hi, I'm " + this.name );
    }
}

const p3 = new Person('Dan', 30, 'Male');
console.log(p3.greet());


// Adding Properties And Methods in an Object
p3.school = "UPenn";
p3.brag = function () {
    console.log("I'm from " + this.school);
};
p3.brag();



// Object Prototype
function F1 () {
    this.p1 = "a",
    this.p2 = "b"
}

const f1 = new F1();
const f2 = new F1();

// adding new property to constructor function
F1.prototype.n1 = "NEW";
console.log(f1.n1);
console.log(f2.n1);



// JavaScript Built-in Constructors
let a1 = new Object();
let a2 = new String("a2");
let a3 = new Number(57);
let a4 = new Boolean(1);
console.log("a1 : " + a1);
console.log("a2 : " + a2);
console.log("a3 : " + a3);
console.log("a4 : " + a4);