/* You can use the throw statement to pass user-defined exceptions. */

// Example 1: try...catch...throw Example
console.log('\nExample 1: try...catch...throw Example');
const n1 = 40;
try {
    if (n1 > 50){
        console.log('Success');
    } else {
        throw new Error('The number is low.');
    }

    console.log('Finished.');
} catch(error){
    console.log('Error caught. Message : ' + error);
}


// Rethrow an Exception
console.log('\nRethrow an Exception');
let n2 = 5;
try {
    throw new Error('Initial throw.');
} catch(error){
    if (n2 > 10){
        console.log('Error Message : ' + error);
        console.log('Error resolved.')
    } else {
        throw new Error('The value is low.')
    }
}