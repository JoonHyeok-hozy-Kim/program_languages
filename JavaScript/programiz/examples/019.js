const lowerBound = parseInt(prompt('Enter the lower bound.'))
const upperBound = parseInt(prompt('Enter the upper bound.'))

let digit;
for (let i=lowerBound; i<=upperBound; i++){
    digit = i.toString().length;
    // document.write(`i : ${i}, digit : ${digit} <br>`);

    ii = i;
    sum = 0;
    while (ii > 0){
        sum += (ii % 10) ** digit;
        ii = Math.floor(ii / 10);
    }

    if (sum == i){
        document.write(`${i} `);
    }
}