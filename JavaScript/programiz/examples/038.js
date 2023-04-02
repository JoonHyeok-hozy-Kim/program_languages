function letterOccurrenceLoop(str, letter) {
    let cnt = 0
    for (let c of str) {
        if (c == letter) {
            cnt++;
        }
    }
    return cnt;
}

function letterOccurrenceRegExp(str, letter) {
    const re = new RegExp(letter, 'g');
    const cnt = str.match(re).length;
    return cnt;
}


S = "abcdaa";
console.log(letterOccurrenceLoop(S, 'a'));
console.log(letterOccurrenceRegExp(S, 'a'));