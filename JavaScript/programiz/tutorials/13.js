let num = 0, sum = 0;

while (num >= 0){
    sum += num;

    num = parseInt(prompt('Enter a positive number : '));
    if (isNaN(num)){
        alert('You entered a string.');
        num = 0;
        continue;
    }
}

document.write(`Sum : ${sum}`);