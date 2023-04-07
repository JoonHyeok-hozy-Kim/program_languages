/** Asynchronous Function
 * We use the async keyword with a function to represent that the function is an asynchronous function.
 * The async function returns a promise.
 */

console.log('\n[Example: Async Function]');
async function af() {
    console.log("Async Function");
    return Promise.resolve(1);
}

af().then(
    function (result) {
        console.log(result);
    }
)


/** await
 * The await keyword is used inside the async function to wait for the asynchronous operation. 
 * The use of await pauses the async function until the promise returns a result (resolve or reject) value.
*/ 
console.log('\n[Example: await]');
let pm = new Promise( function (resolve, reject) {
    setTimeout(function () {
        resolve('Promise resolved')},            
        4000);
})

// async function
async function af2() {
    let result = await pm;  // Wait until the promise resolves (4 secs.)
    console.log(result);
    console.log('af2 finished');    // If await was not used, this will be executed before pm is resolved!
    return pm;
}

af2();




/** Error Handling using catch() 
 * Use the catch() method to catch the error.
*/
console.log('\n[Example: Error Handling using catch() ]');
let pm3 = new Promise(function (resolve, reject) {
    setTimeout( function() {
        reject('pm2 rejected')},
        5000);
})

async function af3() {
    try {
        let result = await pm3;
        console.log(`try : ${result}`);
    } catch(error) {
        console.log(`error : ${error}`);
    }
}

af3();