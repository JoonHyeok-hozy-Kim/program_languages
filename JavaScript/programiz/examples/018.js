let n = 6;
let sum;
let ii;

for (let i=10**(n-1); i<10**n; i++){
    ii = i;
    sum = 0;
    while (ii > 0){
        sum += (ii % 10)**n;
        ii = Math.floor(ii / 10);
    }
    // console.log(i, sum);
    if (i == sum){
        console.log(i);
    }
}