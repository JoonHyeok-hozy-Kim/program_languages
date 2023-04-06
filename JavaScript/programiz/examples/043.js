function in_operator(obj, key){
    hasKey = key in obj;
    if (hasKey) {
        return true;
    } else {
        return false;
    }
}

// Or just use hasOwnProperty();

const person = {
    'a': 1,
    'b': 2,
    'c': 3
}

console.log(in_operator(person, 'a'));
console.log(person.hasOwnProperty('a'));