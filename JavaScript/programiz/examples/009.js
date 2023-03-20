let result;

// Example 1: Generate a Random Number
result = Math.random(); // Range 0 to 1
console.log(result);


// Example 2: Get a Random Number between 1 and 10
let high = 10;
let low = 1;
result = (high - low) * Math.random() + low
console.log(result);


// Example 3: Integer Value between 1 and 10
console.log(Math.floor(result));

// Example 4: Integer Value between Two Numbers (Inclusive)
result = (high - low + 1) * Math.random() + low;
console.log(result)