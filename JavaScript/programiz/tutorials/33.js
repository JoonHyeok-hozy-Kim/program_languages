/* JavaScript ES6 
 - The newer version of JavaScript that was introduced in 2015.
 - ECMAScript is the standard that JavaScript programming language uses. 
 - ECMAScript provides the specification on how JavaScript programming language should work. 
 */



/* let
 - JavaScript let is used to declare variables. 
 - Previously, variables were declared using the var keyword.
 - The variables declared using let are block-scoped.
   - they are only accessible within a particular block.
*/
console.log('\n[JavaScript let]');
let name = 'Sara';
{
    let name = 'Peter';
    console.log(name);
}
console.log(name);


/* JavaScript const
 - The const statement is used to declare constants in JavaScript. 
*/
const const_name = "AJ";


/* JavaScript Arrow Function
 - The const statement is used to declare constants in JavaScript. 
*/
console.log('\n[JavaScript Arrow Function]');
// 1. function expression
let f1 = function(x, y) { return x + y; }
console.log(`function expression, x : ${f1(1, 2)}`);

// 2. arrow function expression
let f2 = (x, y) => x + y;
console.log(`arrow function expression, x : ${f2(1, 2)}`);




/* JavaScript Classes
 - JavaScript class is used to create an object. 
 - Class is similar to a constructor function.
*/
console.log('\n[JavaScript Classes]');
class Person {
    constructor(name){
        this.name = name;
    };

    hi(){
        console.log(`Hi, I'm ${this.name}`);
    };
}
const p1 = new Person('AJ');
p1.hi();


/* Default Parameter Values
 - In the ES6 version, you can pass default values in the function parameters.
*/
console.log('\n[Default Parameter Values]');
function sum_default(x, y=5){
    return x + y;
}
console.log(sum_default(5));
console.log(sum_default(5, 10));


/* JavaScript Template Literals */
console.log('\n[JavaScript Template Literals]');
let tl = "TL"
console.log(`Template Literal : ${tl}`);


/* JavaScript Destructuring
 - The destructuring syntax makes it easier to assign values to a new variable.
*/
console.log('\n[JavaScript Destructuring]');
const girl = {
    firstName : 'Sara',
    age : 25,
    gender: 'Female'
}

let { firstName, age, gender } = girl;
console.log(`${firstName} ${age} ${gender}`)


/* JavaScript import and export */


/* JavaScript Promises
 - Promises are used to handle asynchronous tasks.
*/


/* JavaScript Rest Parameter and Spread Operator
 - You can use the rest parameter to represent an indefinite number of arguments as an array. 
*/
let arr1 = [1, 2];
let arr2 = [...arr1, 3, 4, 5]
console.log(arr1);
console.log(arr2);