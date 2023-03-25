/* Hoisting in JavaScript is a behavior in which a function or a variable can be used before declaration. */
console.log(test1);
var test1;
/* identical to...
    var test1;
    console.log(test1);
*/


// let and const does not allow hoisting

// In JavaScript, initializations are not hoisted.
console.log(test2);
var test2 = 1;
/* identical to...
    var test2;
    console.log(test2);
    test2 = 1;
*/




// When the variable is used inside the function, the variable is hoisted only to the top of the function.
var test3 = 3;

function f1(){
    test4 = "hi";
    console.log(test4);
    var test4;
}

f1();
//console.log(test4); // Error. Local Variable!


/* Function Hoisting : A function can be called before declaring it. */
f2();

function f2(){
    console.log("f2 declared!");
}


// However, when a function is used as an expression, an error occurs because only declarations are hoisted.
f3();

let f3 = function(){
    console.log("f3 declared!");
}