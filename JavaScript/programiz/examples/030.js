function recursiveFactorial(num){
    if (num == 0){
        return 1;
    } else if (num <= 2){
        return num;
    } else {
        return recursiveFactorial(num-1) * num;
    }
}


console.log(recursiveFactorial(5));