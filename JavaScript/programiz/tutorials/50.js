/** JSON stands for Javascript Object Notation. 
 * JSON is a text-based data format that is used to store and transfer data.
 * JSON syntax
    {
        "name": "John",
        "age": 22,
        "gender": "male",

    }
*/

// JSON data
const jsonData = '{ "name": "John", "age": 22 }'; 

// JSON object
const jsonObj = { "name": "John", "age": 22 }

// JSON array
[ "apple", "mango", "banana"]

// JSON array containing objects
const jsonArr = [
    { "name": "John", "age": 22 },
    { "name": "Peter", "age": 20 },
    { "name": "Mark", "age": 23 },
];


console.log('\n[Accessing JSON data]');
console.log(jsonArr[0].name);
console.log(jsonArr[1]["age"]);



console.log('\n[Converting JSON to JavaScript Object]');
const newObj = JSON.parse(jsonData);
console.log(newObj.name);
console.log(newObj.age);


console.log('\n[Converting JavaScript Object to JSON]');
const newData = JSON.stringify(newObj);
console.log(newData);