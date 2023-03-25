function euclidean(n1, n2){
    var big = Math.max(n1);
    var small = Math.min(n2);
    var remainder = big % small;
    while (remainder != 0){
        big = small;
        small = remainder;
        remainder = big % small;
    }
    return small;
}

function LCM(n1, n2){
    var GCD = euclidean(n1, n2);
    return GCD * (n1/GCD) * (n2/GCD);
}

let n1 = 1071;
let n2 = 462;
console.log(`GCD of ${n1} and ${n2} is ${euclidean(n1, n2)}`);
console.log(`LCM of ${n1} and ${n2} is ${LCM(n1, n2)}`);