function findFactors(num){
    let result = [];
    let result_end = [];
    let prev;
    for (let i=1; i<num/2; i++){
        if (i >= prev){
            break;
        }
        if (num%i == 0){
            result.push(i);
            opposite = Math.floor(num/i);
            prev = opposite
            if (i != opposite){
                result_end.unshift(opposite);                        
            }
        }
    }
    
    return result.concat(result_end);

}


console.log(findFactors(36));