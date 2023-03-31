/* Types of Errors
In programming, there can be two types of errors in the code:
 * Syntax Error: Error in the syntax. For example, if you write consol.log('your result');, the above program throws a syntax error. The spelling of console is a mistake in the above code.
 * Runtime Error: This type of error occurs during the execution of the program. For example, calling an invalid function or a variable.
*/



/* JavaScript try...catch Statement */
console.log('\n[JavaScript try...catch Statement]')
const numerator = 100, denominator = 'a';
try {
    console.log(numerator / denominator);
    console.log(a); // a undefined!
} catch(error){
    console.log('An error caught.');
    console.log('Error Message : ' + error);
}


/* JavaScript try...catch...finally Statement */
console.log('\n[JavaScript try...catch...finally Statement]')
try {
    console.log(numerator / denominator);
    console.log(a); // a undefined!
} catch(error){
    console.log('An error caught.');
    console.log('Error Message : ' + error);
} finally{
    console.log('Finally Statement!')
}



/* JavaScript try...catch in setTimeout 
 - The try..catch block must be inside that function to catch an exception inside a timed function.
*/
console.log('\n[JavaScript try...catch in setTimeout]')
console.log('Case 1')
try {
    setTimeout(function() {
        //console.log(a);     // a undefined : returns error!
    }, 3000);
} catch(e){
    console.log("This won't be called!");
}

console.log('Case 2')
setTimeout(function() {
    try{
        console.log(a);     // a undefined.
    } catch(error){
        console.log("Error caught : " + error);
    }
}, 3000)