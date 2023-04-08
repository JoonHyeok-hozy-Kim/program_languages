/** Timing Events
 * In JavaScript, a block of code can be executed in specified time intervals. 
 * These time intervals are called timing events.
 * There are two methods for executing code at specific intervals.
 *    1) setInterval() : The setInterval() method repeats a block of code at every given timing event.
 *    2) setTimeout()
 */


console.log('\n[Basic Example]');
function greet() {
    console.log('Hello world');
}
//setInterval(greet, 1000);   // greet() will be called in every 1 seconds.


console.log('\n[Example 2: Display Time Every 5 Seconds]');
function showTime() {
    let dateTime = new Date();
    let time = dateTime.toLocaleTimeString();
    console.log(time);
}
//let display = setInterval(showTime, 5000);   // showTime() will be called in every 5 seconds.


/** JavaScript clearInterval()
 * If you want to stop setInterval function call, then you can use the clearInterval() method.
 */
console.log('\n[Example 3: Use clearInterval() Method]');
let cnt = 0;
let interval1 = setInterval(function() {
    cnt++;
    if (cnt == 5) {
        clearInterval(interval1);   // clear interval!
    }
    showTime();
}, 2000);


// Passing parameters to the function called by setInterval()
function new_greet(name) {
    console.log(`Hi ${name}`);
}
setInterval(new_greet, 1000, 'AJ');