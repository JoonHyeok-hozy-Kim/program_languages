// Basic
console.log('\n[Basic]');
let f1 = (x, y) => x * y;
console.log(f1(3, 4));


// No Argument Case
console.log('\n[No Argument Case]');
let f2 = () => console.log("Done!");
f2();


// One Argument Case
console.log('\n[One Argument Case]');
let f3 = x => console.log(`One arg : ${x}`);
f3();


// Arrow Function as an Expression
console.log('\n[Arrow Function as an Expression]');
let age = 6;
let is_adult = (age > 18) ?
    () => console.log(`Age ${age} is adult`) :
    () => console.log(`Age ${age} is NOT adult`);
is_adult();


// Multiline Arrow Functions
console.log('\n[Multiline Arrow Functions]');
let fff = (a, b) => {
    let result = a << b;
    return result;
}
console.log(fff(1, 4));


/* this with Arrow Function
 - Inside a regular function, this keyword refers to the function where it is called.
 - However, this is not associated with arrow functions.
 - So whenever you call this, it refers to its parent scope.
*/
console.log('\n[this with Arrow Function]');
function OuterFunc() {
    this.name = 'aaa',
    this.sayName = function() {
        console.log("sayName called");
        let innerFunc = () => {
            console.log(this.name);
        }

        innerFunc();
    }
}
const of = new OuterFunc();
of.sayName();


/* Arguments Binding */
console.log('\n[this with Arrow Function]');
// Regular functions have arguments binding : when you pass arguments to a regular function, you can access them using the arguments keyword.
let fab = function() { console.log(arguments); }
fab(1, 2, 3);

// Arrow function does not support this.
let fabarr = () => {
    try {
        console.log(arguments);
    } catch(error) {
        console.log('Error : ' + error);
    }
}
fabarr();

// Use spread syntax instead.
let fabarrspread = (...n) => { console.log(n); }
fabarrspread(1,2,3,4);



/* Arrow Function with Promises and Callbacks
 - Arrow functions provide better syntax to write promises and callbacks.
*/
// ES5
// asyncFunction().then(function() {
//     return asyncFunction1();
// }).then(function() {
//     return asyncFunction2();
// }).then(function() {
//     finish;
// });

// ES6
// asyncFunction()
// .then(() => asyncFunction1())
// .then(() => asyncFunction2())
// .then(() => finish);



// Warning 1) You should not use arrow functions to create methods inside objects.
console.log('\n[Warning) Do not use arrow functions to create methods inside objects.]');
let obj1 = {
    myName: 'Jack',
    sayName: () => {
        console.log(myName);
    } 
}
try {
    obj1.sayName();
} catch(error){
    console.log('Error : ' + error)
}



// Warning 2)  You cannot use an arrow function as a constructor.
console.log('\n[Warning) Do not use an arrow function as a constructor.]');
let foo = () => {};
try {
    let foo = new foo();
} catch(error) {
    console.log('Error : ' + error);
}
