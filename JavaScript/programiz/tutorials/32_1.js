export function greetPerson(name){
    return `Hello ${name}`;
}
export function sum(x, y){
    return x + y;
}


function f1() { console.log("f1 called.") };
function f2() { console.log("f2 called.") };
// Rename in the module (export file)
export{
    f1 as n1,
    f2 as n2
};


// Default Export
export default function d1() { "default called." };