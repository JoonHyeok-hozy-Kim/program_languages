const num = parseInt(prompt('Enter an integer : '));

// Example 1: Using if...else
if (num % 2 == 0){
    document.write(`${num} is Even`);
} else {
    document.write(`${num} is Odd`);
}

document.write('<br>');

// Example 2: Using Ternary Operator
(num % 2 == 0) ? document.write(`${num} is Even`) : document.write(`${num} is Odd`);