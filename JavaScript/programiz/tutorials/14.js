let a = 1;

switch (a) {
    case "1":
        a = 'one';
        break;
    case 1:
        break;
    case 2:
        a = 'two';
        break;
    
    default:
        a = 'Not found.'
        break;
}

console.log(`The value is ${a}`);



// Example 4: switch With Multiple Case
let fruit = 'apple';

switch (fruit){
    case 'apple':
    case 'mango':
    case 'pineapple':
        console.log(`${fruit} is a fruit.`)
        break;
    
    default:
        console.log(`${fruit} is not a fruit.`)
        break;
}