/* 
In JavaScript, numbers are primitive data types
No separate declaration int, float
*/

const numbers = {
    n1: 3,
    n2: 3.14,
    n3: 5e3,
    n4: 53-3,
    n5: 0xff,
}
for (let n in numbers){
    console.log(`${n} : ${numbers[n]}`)
}


// + Operator with Numbers
console.log('+ Operator with Numbers');
const a = 4;
console.log(a+9);
console.log(a+'9');
// Other operators automatically cast strings to numbers
console.log('Other operators automatically cast strings to numbers');
console.log(a-'3');
console.log(a/'2');
console.log(a*'10');


/* JavaScript NaN
 - NaN(Not a Number) is a keyword that indicates that the value is not a number.
*/
console.log('JavaScript NaN');
const b = 4 - "hi";
console.log(b);
console.log(isNaN(b));
console.log(typeof b);


// JavaScript Infinity
console.log(2/0);
console.log(-2/0);


/* JavaScript BigInt
 - In JavaScript, Number type can only represent numbers less than (253 - 1) and more than -(253 - 1). 
 - However, if you need to use a larger number than that, you can use the BigInt data type.
 - A BigInt number is created by appending n to the end of an integer.
*/
// BigInt value
const bi = 900719925124740998n;
console.log(bi);


/* JavaScript Numbers Are Stored in 64-bit
Numbers	            Exponent	        Sign
52 bits(0 - 51)	    11 bits(52- 62)	    1 bit(63)
*/


// Precision Problems
console.log(0.1+0.2);
console.log((0.1*10 + 0.2*10)/10);



// Number Objects
let no = new Number(24);
let nno = 24;
console.log(typeof no);
console.log(typeof nno);



/* JavaScript Number Methods
Method	                        Description
isNaN()	                        determines whether the passed value is NaN
isFinite()	                    determines whether the passed value is a finite number
isInteger()	                    determines whether the passed value is an integer
isSafeInteger()	                determines whether the passed value is a safe integer
parseFloat(string)	            converts the numeric floating string to floating-point number
parseInt(string, [radix])	    converts the numeric string to integer
toExponential(fractionDigits)	returns a string value for a number in exponential notation
toFixed(digits)	                returns a string value for a number in fixed-point notation
toPrecision()	                returns a string value for a number to a specified precision
toString([radix])	            returns a string value in a specified radix(base)
valueof()	                    returns the numbers value
toLocaleString()	            returns a string with a language sensitive representation of a number
*/


/* JavaScript Number Properties
Property	        Description
EPSILON	            returns the smallest interval between two representable numbers
MAX_SAFE_INTEGER	returns the maximum safe integer
MAX_VALUE	        returns the largest possible value
MIN_SAFE_INTEGER	returns the minimum safe integer
MIN_VALUE	        returns the smallest possible value
NaN	                represents 'Not-a-Number' value
NEGATIVE_INFINITY	represents negative infinity
POSITIVE_INFINITY	represents positive infinity
prototype	        allows the addition of properties to Number objects
*/



// JavaScript Number() Function
let sn = '23';
console.log(typeof sn);
console.log(typeof Number(sn));