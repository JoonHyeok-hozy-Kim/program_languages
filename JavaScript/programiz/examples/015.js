const num = parseInt(prompt('Enter a number : '));
let result = 1;

for (let i=2; i<=num; i++){
    result *= i;
}

document.write(`${num}! = ${result}`);