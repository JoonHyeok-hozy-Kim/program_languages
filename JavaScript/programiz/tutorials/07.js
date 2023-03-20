/*
Implicit Conversion - automatic type conversion
Explicit Conversion - manual type conversion
*/

/* Implicit Conversions */
// Example 1: Implicit Conversion to String
let result;

result = '3' + 2;
console.log(result);

result = '3' + undefined;
console.log(result);


// Example 2: Implicit Conversion to Number
result = '4' - '2';
console.log(result);

result = '4' - 3;
console.log(result);


// Example 3: Non-numeric String Results to NaN
result = 'hello' - 'hji';
console.log(result);


// Example 4: Implicit Boolean Conversion to Number
result = 3 + true;      // true = 1, false = 0
console.log(result);

result = '4' - true;
console.log(result);


// Example 5: null Conversion to Number
result = 11 + null;     // null = 0
console.log(result);


// Example 6: undefined used with number, boolean or null
result = 4 + undefined;
console.log(result);

result = false + undefined;
console.log(result);

result = null + undefined;
console.log(result);

result = undefined + undefined;
console.log(result);








/* Explicit Conversions */
// 1. Convert to Number Explicitly
result = Number('12');
console.log(result);

result = Number(true);
console.log(result);

result = Number(null);
console.log(result);

result = Number('');
console.log(result);

result = Number(' ');
console.log(result);

result = Number('hello'); // NaN
console.log(result);

result = Number(undefined); // NaN
console.log(result);

result = parseInt('12')
console.log(result);

result = parseFloat('12.3')
console.log(result);

result = parseInt('12.3')
console.log(result);

result = Math.floor('12.3')
console.log(result);


// 2. Convert to String Explicitly
result = String(123);
console.log(typeof(result), result);


// 3. Convert to Boolean Explicitly
result = Boolean(null);
console.log(typeof(result), result);

result = Boolean('null');
console.log(typeof(result), result);
