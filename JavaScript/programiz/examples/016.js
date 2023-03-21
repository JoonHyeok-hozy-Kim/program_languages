let n = 0;

while (!(n > 0 && n < 10)){
    n = parseInt(prompt('Enter a positive integer less than 10 : '));
}

for (let i = 1; i < 10; i++){
    document.write(`${n} X ${i} = ${n * i}`);
    document.write('<br>');
}