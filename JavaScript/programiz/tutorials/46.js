/** Callback Function
 * A function that is passed as an argument inside of another function
 */

console.log('\n[Basic Example]');
function greet(name, cb) {
    console.log(`Hi, ${name}`);
    cb();
}

function callMe() {
    console.log("Callback callMe called");
}

greet('AJ', callMe);


/** Application
 * We can wait for the result of a previous function call and then execute another function call.
 * Not like setTimeout(), which milliseconds to wait should be provided, callback can guarantee the sequence.
 */


/** Call back X setTimeout */
console.log('\n[Call back X setTimeout]');
setTimeout(greet, 2000, 'AJ', callMe);