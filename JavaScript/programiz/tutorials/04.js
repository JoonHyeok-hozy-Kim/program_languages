// Primitive Data types
const x = 5;        // number(integer, float)
const y = "hello";  // string
const z = true;     // boolean
let a;              // undefined
b = null;           // null
c = Symbol('hello') // Symbol : data type whose instances are unique and immutable

// Non-Primitive Data type : Object!



// 1. String
s1 = 'a';
s2 = "ab";
s3 = `${x} and ${y}`;
console.log("s1 : ", s1, ", s2 : ", s2, ", s3 : ", s3)

// 2. Number
n1 = 3;
n2 = 3.4;
n3 = 3e5;   // 3 * 10^5
console.log("n1 : ", n1, ", n2 : ", n2, ", n3 : ", n3)

n4 = 3/0;    // Inf
n5 = -3/0;   // -Inf
n6 = "a"/3;  // NaN
console.log("n4 : ", n4, ", n5 : ", n5, ", n6 : ", n6)

// 3. BigInt
// BigInt value
const b1 = 900719925124740998n;
const b2 = b1 + 1n; // Adding two big integers
console.log(b2);    // "900719925124740999n"

// const b3 = 900719925124740998n;
// const b4 = b3 + 1; 
// console.log(result2); // Error! BitInt and number cannot be added


// 4. Boolean
const boo1 = true;
const boo2 = false;

// 5. Undefined : Declared but not assigned
let u1;
let u2 = undefined;
console.log("u1 : ", u1, ", u2 : ", u2);

// 6. null
const nll1 = null;
console.log(nll1);

// 7. Symbol
const sy1 = Symbol('hello');
const sy2 = Symbol('hello');


// 8. Object
const ob1 = {
    att1: 'a',
    att2: null,
    att3: -4
};


// typeof()
console.log(typeof(sy1));
console.log(typeof(ob1));