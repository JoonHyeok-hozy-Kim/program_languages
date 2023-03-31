// Basic Case
console.log('\n[Basic Case]');
function bsum(x = 1, y = 2) {
    console.log(x + y);
}
bsum();


// Using Expressions as Default Values
console.log('\n[Using Expressions as Default Values]');
function esum(x = 1, y = x, z = x + y) {
    console.log(x + y + z);
}
esum();


// Passing Function Value as Default Value
console.log('\n[Passing Function Value as Default Value]');
const fv = () => 7;
function fsum(x=2, y=fv()){
    console.log(x * y);
}
fsum();


// Passing undefined Value
console.log('\n[Passing undefined Value]');
function undef(x = 1){
    console.log(x);
}
let a;
undef(a);