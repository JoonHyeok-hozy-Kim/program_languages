/** In JavaScript, date and time are represented by the Date object. 
 * The Date object provides the date and time information and also provides various methods. 
 */


console.log('\n[Creating Date object]');
const timeNow = new Date();
console.log(timeNow);


console.log('\n[Creating Date milliseconds since Jan 1, 1970]');
const t1 = new Date(0);                 // 1970.01.01
console.log(t1);
const t2 = new Date(2000000000000);     // 2000000000000 milliseconds from 1970.01.01
console.log(t2);


console.log('\n[Creating Date with String]');
const d1 = new Date("2023-04-08");          // ISO Format
console.log(d1);
const d2 = new Date("2024");                // Passing only year.
console.log(d2);
const d3 = new Date("2022-04-27T04:00Z");   // ISO with specific time
console.log(d3);


console.log('\n[Short and Long date format]');
const dt1 = new Date("03/25/2016");         // Short Date Format
console.log(dt1);
const dt2 = new Date("Jul 1 2020");         // Long Date Format
console.log(dt2);
const dt3 = new Date("1 Apr 2023");         // Long Date Format
console.log(dt3);
const dt4 = new Date("30 April 2023");      // Long Date Format
console.log(dt4);
const dt5 = new Date("JULY, 1, 2020");      // Long Date Format
console.log(dt5);


console.log('\n[new Date(year, month, day, hours, minutes, seconds, milliseconds)]');
const dd1 = new Date(2020, 1, 20, 4, 12, 11, 0);
console.log(dd1);
const dd2 = new Date(2023, 3, 9);
console.log(dd2);


/* JavaScript Date Methods

Method	        Description
now()	        Returns the numeric value corresponding to the current time (the number of milliseconds elapsed since January 1, 1970 00:00:00 UTC)
getFullYear()	Gets the year according to local time
getMonth()	    Gets the month, from 0 to 11 according to local time
getDate()	    Gets the day of the month (1–31) according to local time
getDay()	    Gets the day of the week (0-6) according to local time
getHours()	    Gets the hour from 0 to 23 according to local time
getMinutes	    Gets the minute from 0 to 59 according to local time
getUTCDate()	Gets the day of the month (1–31) according to universal time
setFullYear()	Sets the full year according to local time
setMonth()	    Sets the month according to local time
setDate()	    Sets the day of the month according to local time
setUTCDate()	Sets the day of the month according to universal time
*/

console.log('\n[Date Methods Examples]');
const nowInMilliseconds = Date.now();
console.log(nowInMilliseconds);

const tt = new Date;
const td = tt.getDate();
console.log(`${tt} / ${td}`);


console.log('\n[Date Formatting]');
const currDate = new Date();
const dateOnly = currDate.getDate();
const monthOnly = currDate.getMonth();
const yearOnly = currDate.getFullYear();
console.log(dateOnly, monthOnly+1, yearOnly);