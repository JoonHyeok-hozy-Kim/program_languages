// Basic
var n1 = 'Jack';
console.log(`My name is ${n1}.`);


// Quotation inside same the quotation : Use \ or the template literal
console.log("Use \"quote\" like this.");
console.log('Use \'quote\' like this.');
console.log(`Use "quote" like this.`);      // Using the template literal


// Multiline Strings
console.log('\n[Multiline Strings]');
var long1 = 'abcd' + 
'efgh' +
'ijkl';
console.log(long1);

var long2 = `abcd
efgh
ijkl`;
console.log(long2);


// Expression Interpolation
console.log('\n[Expression Interpolation]');
var r1 = 8;
console.log(`${r1 < 10 ? 'Too low' : 'Too high'}`);


// Tagged Templates
console.log('\n[Tagged Templates]');
function tagExample(str){
    return str;
}
var r2 = tagExample`Given String`;
console.log(r2);

const n2 = 'AJ';
const greet = true;
function tagExample2(str, name){
    let str0 = str[0];
    let str1 = str[1];

    if (greet) {
        return `${str0}${name}${str1}`;
    }
}
const r3 = tagExample2`Hello ${n2}, how are you?`;
console.log(r3);