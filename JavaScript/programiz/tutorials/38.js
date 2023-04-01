// Create JavaScript Map
console.log('\n[Create JavaScript Map]');
const map1 = new Map();
console.log(map1);

// Insert Item to Map
console.log('\n[Insert Item to Map]');
let map2 = new Map();
map2.set('info', {name: 'AJ', age: 28});    // Ust set() to insert elements.
console.log(map2);
obj1 = {}
map2.set(obj1, {name: 'hozy', age: 30});
console.log(map2);

// Access Map Elements
console.log('\n[Access Map Elements]');
let map3 = new Map();
map3.set('info', {name: 'AJ', age: 28});
console.log(map3.get('info'));              // Use get() to access elements.

// Check Map Elements
console.log('\n[Check Map Elements]');
console.log(map3.has('info'))               // Use has()

// Removing Elements
console.log('\n[Removing Elements]');
map3.delete('info');                        // Use delete()
console.log(map3);            
map2.clear();                               // Use delete()
console.log(map2);            

// Map Size
console.log('\n[Map Size]');
map3.set('info', {name: 'AJ', age: 28});
console.log(map3.size);                     // size property.

// Iterate Through a Map
console.log('\n[Iterate Through a Map]');
map3.set('info1', {name: 'hozy', age: 30});
map3.set('info2', {name: 'ap', age: 100});
for (let [key, value] of map3) {
    console.log(`${key} - ${value}`);
}

// Iterate Over Map Keys
console.log('\n[Iterate Over Map Keys]');
for (let k of map3.keys()) {
    console.log(`${k} - ${map3.get(k)}`);
}

// Get Key/Values of Map
console.log('\n[Get Key/Values of Map]');
for (let e of map3.entries()){
    console.log(`${e[0]} : ${e[1]}`);
}



////////////////////////////////////////////////
/* WeakMap() : NOT iterable! */
console.log('\n[WeakMap]');
const wm = new WeakMap();
console.log(wm);

let obj4 = {};
let obj5 = {};
let obj6 = {};
wm.set(obj4, 'hello');
console.log(wm);
console.log(wm.get(obj4));
console.log(wm.has(obj4));
wm.set(obj5, 'hi');
wm.set(obj6, 'hola');
console.log(wm);
wm.delete(obj4);
console.log(wm + ' / ' + wm.has(obj4));
