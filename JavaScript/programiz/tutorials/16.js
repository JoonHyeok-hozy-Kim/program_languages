/* Global Scope 
- A variable declared at the top of a program or outside of a function is considered a global scope variable.
*/
let g1 = "global 1";

function f1(){
    console.log(g1);
}

f1();


/* Global Scope 
- If a variable is used without declaring it, that variable automatically becomes a global variable.
*/

function f2(){
    g2 = "global 2";
}

f2();
console.log(g2);


/* Local Scope 
Example 1: Local Scope Variable
*/

function f3(){
    let l1 = "local 1";
    console.log(l1);
}

f3();
// console.log(l1); // ERROR!


/* Local Scope 
Example 2: block-scoped Variable
*/
function f4(){
    if (1==1){
        let l2 = "local2";
        console.log(`In the block, l2 : ${l2}`);
    }
    //console.log(`Out of the block, l2 : ${l2}`);    // Error!
}

f4();