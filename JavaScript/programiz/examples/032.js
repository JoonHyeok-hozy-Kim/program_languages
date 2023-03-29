function ASCII(char){
    return char.charCodeAt(0)
}

function ASCII2(char){
    return char.codePointAt(0)
}

console.log(ASCII('a'));
console.log(ASCII2('a'));