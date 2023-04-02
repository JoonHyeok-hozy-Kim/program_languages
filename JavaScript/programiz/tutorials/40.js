/** Destructuring Assignment
 * The destructuring assignment introduced in ES6 makes it easy to assign array values and object properties to distinct variables.
*/


// Comparison
console.log('\n[Comparison]');
const person = {
    name: 'a',
    age: 1,
    gender: 'female'
};

// Without Destructuring
let n1 = person.name;
let a1 = person.age;
let g1 = person.gender;
console.log(n1 + ' ' + a1 + ' ' + g1);

// With Destructuring
let { name, age, gender } = person;
console.log(name + ' ' + age + ' ' + gender);   // Must use same identifier in the Object!


// Array Destructuring
console.log('\n[Array Destructuring]');
const arr1 = [1,2,3];
const [x, y, z] = arr1;
console.log(x, y, z);


// Assign Default Values
console.log('\n[Assign Default Values]');
const arr2 = [77];
const [a = 1, b = 2] = arr2;
console.log(a, b); 



// Swapping Variables
let x1 = 1;
let x2 = 0;

console.log(x1, x2);
[x1, x2] = [x2, x1];
console.log(x1, x2);



// Skip Items
let arr3 = [1,2,3,4];
let [y1, y2, , y3] = arr3;
console.log(y1, y2, y3);



// Assign Remaining Elements to a Single Variable
const arr4 = [1,2,3,4];
let [z1, ...z2] = arr4;
console.log(z1, z2);

const student = {
    nn: '1',
    aa: 2,
    gg: 'a'
}
let {nn, ...rest1} = student;
console.log(nn, rest1);



// Nested Destructuring Assignment
const arr5 = [1, [2, 3]];
const [m1, [m2, m3]] = arr5;
console.log(m1, m2, m3);