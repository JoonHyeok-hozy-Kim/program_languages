function checkPalindrome(S){
    let start = 0;
    let end = S.length - 1;

    while (start < end){
        if (S[start++] != S[end--]){
            return false;
        }
    }
    return true;
}

console.log(checkPalindrome('aba'));
console.log(checkPalindrome('a'));
console.log(checkPalindrome('abcd'));
console.log(checkPalindrome('123aaaa321'));
console.log(checkPalindrome(''));