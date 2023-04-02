function countVowels(S) {
    let cnt = 0;
    let V = "aeiou";
    for (v of V) {
        for (c of S) {
            if (v == c) {
                cnt++;
            }
        }
    }
    return cnt;
}

function countVowelsRegExp(S) {
    return S.match(/[aeiou]/gi).length;
}

console.log(countVowels("apple"));
console.log(countVowelsRegExp("apple"));