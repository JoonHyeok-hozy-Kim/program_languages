/* Declaring a Function */
function greet(name) {
    // function body
    document.write(`hello ${name} <br>`);
}

/* Calling a Function */
greet('Joon');


/* Function Return */
function add(n1, n2){
    return n1+n2;
}

let n1 = parseInt(prompt('Enter a number'))
let n2 = parseInt(prompt('Enter another number'))
document.write(`${n1} + ${n2} = ${add(n1, n2)}<br>`)


/* Function Expressions */
let x = function(num) { return num * num}
document.write(x(4) + '<br>');

let y = x(10);
document.write(y + '<br>');