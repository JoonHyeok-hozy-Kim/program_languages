// Variable declaration
var x;  // used in the older versions of JavaScript; function scoped;
let y;  // the new way of declaring variables starting ES6 (ES2015); block scoped;
console.log(x + "\n");

// recommended to use let instead of var
let a = 3, b = 2, c = 1;
console.log(a, b, c, "\n");



// Rules for Naming JavaScript Variables
// 1. Variable names must start with either a letter, an underscore _, or the dollar sign $.
let k = "hello";
let _k = "hi";
let $k = "hola";

// 2. Variable names cannot start with numbers.
// 3. JavaScript is case-sensitive. So y and Y are different variables. 
let m = 11;
let M = 12;

// 4. Keywords cannot be used as variable names.






// JavaScript Constants
const aa = 10;  // Once a constant is initialized, we cannot change its value.
// aa = 3;
console.log(aa, "\n");