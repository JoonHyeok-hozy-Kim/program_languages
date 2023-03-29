let s1 = 'abcabc';
let s2 = "bbbbbb";
let s3 = `${s1} and ${s2}`;

console.log(s1[3]);

// JavaScript Strings are immutable
s1[0] = 'X';
console.log(s1);

// JavaScript is Case-Sensitive
console.log('a' === 'A');

// JavaScript Multiline Strings
let ms1 = "abceee\
dddddd\
asdfasdf";
console.log(ms1);

// JavaScript String Length
console.log(ms1.length);

// JavaScript String Objects
const obj1 = "hi";
const obj2 = new String("hi");
console.log(typeof obj1);   // string
console.log(typeof obj2);   // object


/* JavaScript String Methods

Method	                Description
charAt(index)	        returns the character at the specified index
concat()	            joins two or more strings
replace()	            replaces a string with another string
split()	                converts the string to an array of strings
substr(start, length)	returns a part of a string
substring(start,end)	returns a part of a string
slice(start, end)	    returns a part of a string
toLowerCase()	        returns the passed string in lower case
toUpperCase()	        returns the passed string in upper case
trim()	                removes whitespace from the strings
includes()	            searches for a string and returns a boolean value
search()	            searches for a string and returns a position of a match
*/

const text1 = "hello";
const text2 = "world";
const text3 = "     JavaScript     ";

console.log(text1.concat(" ", text2));
console.log(text1.toUpperCase());
console.log(text3.trim());
console.log(text1.split('l'));
console.log(text1.slice(2, 4));


/* Escape Character
Code	Output
\"	    include double quote
\\	    include backslash
\n	    new line
\r	    carriage return
\v	    vertical tab
\t	    horizontal tab
\b	    backspace
\f	    form feed
*/
const name1 = 'My name is \'Peter\'.';
console.log(name1);