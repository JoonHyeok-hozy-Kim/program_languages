/** Promise
 * It is used to find out if the asynchronous operation is successfully completed or not. 
 * Three States : Pending / Fulfilled / Rejected
 * */


console.log('\n[Create a Promise]');
const count = true;
let countValue = new Promise(function (resolve, reject) {
    if (count) {
        resolve("[countValue resolve] There is a count value");
    } else {
        reject("[countValue reject] There is NO count value");
    }
});
console.log(countValue);


/** Promise Chaining
 * Chaining promises using methods : then(), catch(), and finally().
 */


/** then() method
 * used with the callback when the promise is successfully fulfilled or resolved.
 */
console.log('\n[Chaining the Promise with then()]');
countValue
    .then(function successValue(result1) {
        console.log(result1);
    })

    .then(function successValue1() {
        console.log("Additional Function can be added like this!");
    })

    .finally(function final1() {
        console.log('countValue finally.');
    })


/** catch() method
 * used with the callback when the promise is rejected or if an error occurs.
 */
console.log('\n[Chaining the Promise with catch()]');
const count2 = false;
let countValue2 = new Promise(function (resolve, reject) {
    if (count2) {
        resolve("[countValue2 resolve] There is a count value");
    } else {
        reject("[countValue2 reject] There is NO count value");
    }
});

countValue2
    .then(function successValue2(result2) {
        console.log(`countValue2 then : ${result2}`);
    })
    .catch(function errorValue(result3) {
        console.log(`countValue2 catch : ${result3}`);
    })
    .finally(function finally2() {
        console.log('countValue2 finally.');
    })


/* JavaScript Promise Methods

Method	                Description
all(iterable)	        Waits for all promises to be resolved or any one to be rejected
allSettled(iterable)	Waits until all promises are either resolved or rejected
any(iterable)	        Returns the promise value as soon as any one of the promises is fulfilled
race(iterable)	        Wait until any of the promises is resolved or rejected
reject(reason)	        Returns a new Promise object that is rejected for the given reason
resolve(value)	        Returns a new Promise object that is resolved with the given value
catch()	                Appends the rejection handler callback
then()	                Appends the resolved handler callback
finally()	            Appends a handler to the promise
*/