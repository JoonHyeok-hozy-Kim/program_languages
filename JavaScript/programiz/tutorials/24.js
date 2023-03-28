// How to create an Array
const arr1 = ["a", 1, true, [100, 200, 300], function hi() { console.log("hi"); }];
const arr2 = new Array("a", 1, true, [100, 200, 300], function hi() { console.log("hi"); });


// How to access elements in an Array
for (let i=0; i<arr1.length; i++){
    console.log(arr1[i]);
}

// How to add an element to an array
arr1.push("end");
console.log(arr1);
arr1.unshift("start");
console.log(arr1);

// Change the Elements of an Array
arr1[Math.floor(arr1.length / 2)] = "mid";
console.log(arr1)

// Remove an Element from an Array
arr1.pop();
console.log(arr1);
arr1.shift();
console.log(arr1);


/*
Some of the commonly used JavaScript array methods are:

Method	    Description
concat()	joins two or more arrays and returns a result
indexOf()	searches an element of an array and returns its position
find()	    returns the first value of an array element that passes a test
findIndex()	returns the first index of an array element that passes a test
forEach()	calls a function for each element
includes()	checks if an array contains a specified element
push()	    aads a new element to the end of an array and returns the new length of an array
unshift()	adds a new element to the beginning of an array and returns the new length of an array
pop()	    removes the last element of an array and returns the removed element
shift()	    removes the first element of an array and returns the removed element
sort()	    sorts the elements alphabetically in strings and in ascending order
slice()	    selects the part of an array and returns the new array
splice()	removes or replaces existing elements and/or adds new elements
*/