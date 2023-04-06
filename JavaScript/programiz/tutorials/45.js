/** The setTimeout() method executes a block of code after the specified time. 
 * The method executes the code only once.
 * Syntax : setTimeout(function, milliseconds, parameter1, parameter2, ...);
 */


console.log('\n[Example 1: Display a Text Once After 3 Second]');
function greet(someone) {
    console.log(`Hi ${someone}`);
}

setTimeout(greet, 3000, 1);    // after 3 seconds.
console.log('Log after greet()');


console.log('\n[Concept) Interval ID]');
let intervalID = setTimeout(greet, 3500, 2);
console.log(intervalID);


console.log('\n[Example 2: Display Time Every 3 Second]');
function showTime(sec) {
    let dateTime = new Date();
    let time = dateTime.toLocaleTimeString();

    console.log(time);
    if (sec-3 < 3) {
        return;
    }
    setTimeout(showTime, 3000, sec-3);
}
showTime(10);


console.log('\n[Example 3: Use clearTimeout() Method]');
// program to stop the setTimeout() method

let count = 0;
// function creation
function increaseCount(){
    // increasing the count by 1
    count += 1;
    console.log(count)
}

let id = setTimeout(increaseCount, 3000);

// clearTimeout
clearTimeout(id); 
console.log('setTimeout is stopped.');