function sortAlpha(S) {
    // console.log(`before : ${S}`);
    if (S.length <= 1) {
        return S
    }

    let mid = Math.floor(S.length / 2);
    let s1 = sortAlpha(S.slice(0, mid));
    let s2 = sortAlpha(S.slice(mid, S.length));

    let result = _merge(S, s1, s2);

    // console.log(` -> after : ${S}`);
    return result
}

function _merge(S, s1, s2) {
    let i1 = 0;
    let i2 = 0;
    let temp = [];
    for (let i=0; i<S.length; i++) { temp.push(null); }
    while (i1 + i2 < temp.length) {
        if (i2 == s2.length || (i1 < s1.length && _le(s1[i1], s2[i2]))) {
            temp[i1+i2] = s1[i1];
            i1++;
        } else {
            temp[i1+i2] = s2[i2];
            i2++;
        }
    }
    return temp.join('');
}

function _le(a, b){
    return a.charCodeAt(0) <= b.charCodeAt(0)
}

// console.log(_le('a', 'b'));
// console.log(_le('z'[0], 'b'[0]));
// console.log(_le('z', 'z'));

let str = "fiwejfalsdf";
let sstr = sortAlpha(str);
console.log(sstr); 