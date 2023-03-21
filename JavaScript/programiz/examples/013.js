const num = parseInt(prompt('Enter a number : '));
let result = true;

if (num == 1){
    result = false;
} else {
    for (let i = 2; i <= num / 2; i++){
        if (num % i == 0){
            result = false;
            break;
        }
    }
}

document.write(`${num} is `);
if (!result){
    document.write('not ');
}
document.write('a prime number.');