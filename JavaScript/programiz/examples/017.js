let num = 0;
let fibo_prev = 1;
let fibo_curr = 1;
let temp;

while (num <= 0){
    num = parseInt(prompt('Enter a positive integer.'));
}

for (let i=0; i<num; i++){
    if (i < 2){
        document.write('1 ');
    } else {
        temp = fibo_prev + fibo_curr;
        document.write(`${temp} `);
        fibo_prev = fibo_curr;
        fibo_curr = temp;
    }
}