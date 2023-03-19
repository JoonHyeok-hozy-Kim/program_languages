let a = parseInt(prompt('Enter value 1 : '));
let b = parseInt(prompt('Enter value 2 : '));



// Sol1) Using temporary variable
let temp;
temp = a;
a = b;
b = temp;

console.log(`After swap1 val1 : ${a}`);
console.log(`After swap1 val2 : ${b}`);


// Sol2) Using es6(ES2015) Destructuring assignment
[a, b] = [b, a]
console.log(`After swap2 val1 : ${a}`);
console.log(`After swap2 val2 : ${b}`);


// Example 3: Using Arithmetic Operators
a = a+b;
b = a-b;
a = a-b;
console.log(`After swap3 val1 : ${a}`);
console.log(`After swap3 val2 : ${b}`);


// Example 4: Using Bitwise XOR operator
a = a^b;
b = a^b;
a = a^b;
console.log(`After swap4 val1 : ${a}`);
console.log(`After swap4 val2 : ${b}`);