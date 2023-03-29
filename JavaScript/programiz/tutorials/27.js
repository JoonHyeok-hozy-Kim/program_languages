// Example 1: Iterate Through an Object
const student = {
    name: "AJ",
    class: "Advanced",
    age: "28"
}

for (let key in student){
    console.log(`${key} => ${student[key]}`);
}


// Example 2: Update Values of Properties
const salaries = {
    Jack: 24000,
    Paul: 34000,
    Monica : 55000,
}

for (let person in salaries){
    console.log(`${person} : $${salaries[person]}`);
}


// for...in with Strings
const s1 = "code";
for (let i in s1){
    console.log(`i: ${i}, s1[i]: ${s1[i]}`);
}

// for...in with Arrays
const arr1 = [ 'hello', 1, 'JavaScript' ];
for (let x in arr1){
    console.log(arr1[x]);
}
for (x of arr1){
    console.log(x);
}