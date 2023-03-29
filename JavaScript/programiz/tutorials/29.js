/* JavaScript Symbol
 - The JavaScript ES6 introduced a new primitive data type called Symbol. 
 - Symbols are immutable (cannot be changed) and are unique.
*/
const s1 = "hello";
const s2 = "hello";
console.log(s1 == s2);

const sy1 = Symbol("hello");
const sy2 = Symbol("hello");
console.log(sy1 == sy2);

console.log(typeof sy1);


// Access Symbol Description
console.log(sy1.description);

// Add Symbol as an Object Key
let id = Symbol('id');
let person = {
    name: "Jack",
    [id]: 123,           // 
    age: 31,
}
console.log(person);
console.log(person[id]);

// Symbols are not included in for...in Loop
for (let key in person){
    console.log(`key: ${key}, val : ${person[key]}`);
}


/* Benefit of Using Symbols in Object
 - If the same code snippet is used in various programs, then it is better to use Symbols in the object key.
 - It's because you can use the same key name in different codes and avoid duplication issues.
    i.e) Symbol('id') has identical value when used in different programs.
*/

/* Symbol Methods
Method	    Description
for()	    Searches for existing symbols
keyFor()	Returns a shared symbol key from the global symbol registry.
toSource()	Returns a string containing the source of the Symbol object
toString()	Returns a string containing the description of the Symbol
valueOf()	Returns the primitive value of the Symbol object.
*/
let sym1 = Symbol.for('hello');
let sym2 = Symbol.for('id');
console.log( Symbol.keyFor(sym1));
console.log( Symbol.keyFor(sym2));


/* Symbol Properties
Properties	        Description
asyncIterator	    Returns the default AsyncIterator for an object
hasInstance	        Determines if a constructor object recognizes an object as its instance
isConcatSpreadable	Indicates if an object should be flattened to its array elements
iterator	        Returns the default iterator for an object
match	            Matches against a string
matchAll	        Returns an iterator that yields matches of the regular expression against a string
replace	            Replaces matched substrings of a string
search	            Returns the index within a string that matches the regular expression
split	            Splits a string at the indices that match a regular expression
species	            Creates derived objects
toPrimitive	        Converts an object to a primitive value
toStringTag	        Gives the default description of an object
description	        Returns a string containing the description of the symbol
*/
const x = Symbol('hey');
console.log(x.description);
const stringArray = ['a', 'b', 'c'];
const numberArray = [1, 2, 3]

numberArray[Symbol.isConcatSpreadable] = false;

let result = stringArray.concat(numberArray);
console.log(result);