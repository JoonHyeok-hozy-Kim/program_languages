// Example 1: Built in function
const number = 4;
const result = Math.sqrt(number);
console.log(`Square Root ${number} = ${result}`);



// Example 2: Square Root of Different Data Types
const n1 = 2.25;
const n2 = -4;
const n3 = 'hello';

const sn1 = Math.sqrt(n1);  // 1.5
const sn2 = Math.sqrt(n2);  // NaN
const sn3 = Math.sqrt(n3);  // NaN

console.log(`Square Root ${n1} = ${sn1}`);
console.log(`Square Root ${n2} = ${sn2}`);
console.log(`Square Root ${n3} = ${sn3}`);