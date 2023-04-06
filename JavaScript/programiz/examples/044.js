const person = {
    name: 'John',
    age: 21,
}


/** Shallow Copy */
let p2 = person;



/** Deep Copy */
// 1. Using Object.assign()
const p3 = Object.assign({}, person);

// 2. Using Spread Syntax
const p4 = {... person};

// 3. Using JSON.parse()
const p5 = JSON.parse(JSON.stringify(person));