function decimalToBinary(num){
    S = [];
    while (num > 0){
        if (num % 2 != 0){
            S.unshift('1');
        } else {
            S.unshift('0');
        }
        num = Math.floor(num/2);
    }
    return S.join('');
}


for (let x = 0; x < 20; x++){
    console.log(decimalToBinary(x));
}