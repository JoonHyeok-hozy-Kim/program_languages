/** Nested Function
 * A function that is contained by another function.
 */

console.log('\n[Nested Function Example]');
// outer function
function greet1(name) {
    // inner function
    function displayName() {
        console.log(`Hi, ${name}`);
    }
    displayName();
}
greet1('AJ');


/** Returning a Function
 * In JavaScript, you can also return a function within a function.
 */

console.log('\n[Returning a Function Example]');
function greet2(name) {
    function displayName() {
        console.log(`Hi, ${name}`);
    }
    return displayName;
}
const g2 = greet2('hozy');
console.log(g2);
g2();


/** Closures
 * In JavaScript, closure provides access to the outer scope of a function from inside the inner function, even after the outer function has closed. 
 */

console.log('\n[Closure Example 1]');
function greet3() {
    // Variable defined outside the inner function
    let name = 'John';

    function displayName() {
        return `Hi, ${name}`;
    }

    return displayName;
}
const g3 = greet3();
console.log(g3);
console.log(g3());



console.log('\n[Closure Example 2]');
function calculate(x) {
    function multiply(y) {
        return x * y;
    }
    return multiply;
}
const multiply3 = calculate(3);
console.log(multiply3(7));
const multiply4 = calculate(4);
console.log(multiply4(13));



console.log('\n[Closure Example 3]');
function sum() {
    let a = 0;
    function increaseSum() {
        return a = a+1;
    }
    return increaseSum;
}
let x = sum();
let a = 5;
console.log(x());
console.log(x());
console.log(a);