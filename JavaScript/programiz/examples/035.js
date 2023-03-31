function replaceRedBlue(S) {
    const regex = /red/g;
    return S.replace(regex, 'blue');
}

var string = 'Mr Red has a red house and a red car';
console.log(replaceRedBlue(string));