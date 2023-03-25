function countDown(number){
    console.log(number);
    const newNumber = number - 1
    if (newNumber > 0){
        countDown(newNumber);
    }
}
console.log("Count Down");
countDown(5);


function Factorial(n){
    if (n <= 1){
        return 1;
    }
    return n * Factorial(n-1);
}

console.log("Factorial");
for (let i=0; i<=10; i++){
    console.log(`${i}! = ${Factorial(i)}`);
}