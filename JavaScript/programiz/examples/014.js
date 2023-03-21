const lowerBound = parseInt(prompt('Enter the lower bound : '));
const upperBound = parseInt(prompt('Enter the upper bound : '));

let num = 2;
let primeNumbers = []
let isPrime;

while (num <= upperBound){
    isPrime = true;
    for (let i = 0; i < primeNumbers.length; i++){
        if (num % primeNumbers[i] == 0){
            isPrime = false;
            break;
        }
    }

    if (isPrime){
        primeNumbers.push(num);
        if (num >= lowerBound){
            document.write(num + " ");
        }
    }
    num++;
}