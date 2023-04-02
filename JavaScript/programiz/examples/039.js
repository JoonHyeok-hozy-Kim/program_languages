function firstLetterToUpper(S) {
    return S.charAt(0).toUpperCase() + S.slice(1);     
};

function firstLetterToUpperRegExp(S) {
    return S.replace(/^./, S[0].toUpperCase());
};

const str = "abd";
const result1 = firstLetterToUpper(str);
console.log(result1);

const result2 = firstLetterToUpperRegExp(str);
console.log(result2);