// Basic Example
console.log('\n[Basic Example]');
const arr1 = ['My', 'name', 'is', 'dan'];
console.log(...arr1);

// Copy Array Using Spread Operator
console.log('\n[Copy Array Using Spread Operator]');
const arr2 = [...arr1, 'and', 'AJ'];
console.log(...arr2);

// Clone Array Using Spread Operator
console.log('\n[Clone Array Using Spread Operator]');
let arr3 = [1,2,3];
let arr4 = arr3;        // Shallow copy
let arr5 = [...arr3];   // Deep copy
console.log(`arr3 : ${arr3}`);
console.log(`arr4 : ${arr4}`);
console.log(`arr5 : ${arr5}`);
arr3.push(4);
console.log(`arr3 : ${arr3}`);
console.log(`arr4 : ${arr4}`);
console.log(`arr5 : ${arr5}`);

// Spread Operator with Object
console.log('\n[Spread Operator with Object]');
const obj1 = { x: 1, y: 2 };
const obj2 = { z: 3 };
const obj3 = { ...obj1, ...obj2 };
console.log(obj3);

// Rest Parameter
console.log('\n[Rest Parameter]');
let func1 = function(...args) {
    console.log(args);
}
func1(3);
func1(1,2,3);

function sum1(x, y, z){
    console.log(x + y + z);
}
const nums1 = [1,2,3,4];
sum1(...nums1);