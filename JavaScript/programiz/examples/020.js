const operatorSet = ['+', '-', '*', '/'];
let operator = null;
let n1;
let n2;

while (true){
    while (!(operator == '+' || operator == '-'|| operator == '*' || operator == '/')){
        operator = prompt('Enter an operator.');
    }

    n1 = parseInt(prompt('Enter number 1.'));
    n2 = parseInt(prompt('Enter number 2.'));

    if (!(operator == '/' && n2 == 0)){
        break;
    }
}

document.write(`${n1} ${operator} ${n2} = `);
let result;
switch (operator){
    case '+':
        result = n1 + n2;
        break;
    case '-':
        result = n1 - n2;
        break;
    case '*':
        result = n1 * n2;
        break;
    case '/':
        result = n1 / n2;
        break;
    default:        
}
document.write(result);