/* Global Scope 
- A variable declared at the top of a program or outside of a function is considered a global scope variable.
*/
let a = "hello";

function greet(){
    document.write(a + "<br>");
}

greet();