function for_loop_sum(number){
    var result = 0;
    for (let i=1; i<=number; i++){
        result += i;
    }
    return result;
}

function while_loop_sum(number){
    var result = 0;
    while (number > 0){
        result += number--;
    }
    return result;
}

console.log(`for_loop_sum : ${for_loop_sum(10)}`);
console.log(`while_loop_sum : ${while_loop_sum(10)}`);