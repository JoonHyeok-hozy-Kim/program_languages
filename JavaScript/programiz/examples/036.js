function reverseString(S) {
    let temp = S.split('');
    let s = 0;
    let e = S.length - 1;
    let x;
    while (s < e) {
        x = temp[s];
        temp[s] = temp[e];
        temp[e] = x;
        s++;
        e--;
    }
    return temp.join('');
}

console.log(reverseString('asdfjoiasdfj'));