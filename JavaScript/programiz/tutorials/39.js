// Basic
console.log('\n[Basic]');
const set1 = new Set();
console.log(set1);

const set2 = new Set([1, 'hello', {count: true}]);
console.log(set2);


// Access Set Elements
console.log('\n[Access Set Elements]');
console.log(set2.values());

if (set2.has(1)){
    console.log('has 1');
}


// Adding New Elements
console.log('\n[Adding New Elements]');
for (let i=0; i<3; i++){
    set1.add(i);
}
console.log(set1.values());


// Removing Elements
console.log('\n[Removing Elements]');
set1.delete(2);
console.log(set1.values());

set1.clear();
console.log(set1.values());


// Iterate Sets
console.log('\n[Iterate Sets]');
for (let i of set2){
    console.log(i);
}



/** JavaScript WeakSet
 * The WeakSet is similar to a Set. 
 * However, WeakSet can only contain objects whereas a Set can contain any data types such as strings, numbers, objects, etc.
 * WeakSets Are Not iterable.
 */
console.log('\n[WeakSet]');
const ws = new WeakSet();

let o1 = {
    message: 'Hi',
    sendMessage: true
};

ws.add(o1);                 // adding an object!
console.log(ws.has(o1));    // has
ws.delete(o1);              // delete



/** Mathematical Set Operations
 * In JavaScript, Set does not provide built-in methods for performing mathematical operations such as union, intersection, difference, etc.
 */

function union(a, b) {
    let unionSet = new Set(a);
    for (let i of b) {
        unionSet.add(i);
    }
    return unionSet;
}

function intersection(a, b) {
    let intersectionSet = new Set();
    for (let i of a) {
        if (b.has(i)) {
            intersectionSet.add(i);
        }
    }
    return intersectionSet;
}

function difference(a, b) {
    let differenceSet = new Set();
    for (let i of a) {
        if (!b.has(i)) {
            differenceSet.add(i);
        }
    }
    return differenceSet;
}

function subset(a, b) {
    for (let i of b) {
        if (!a.has(i)) {
            return false;
        }
    }
    return true;
}