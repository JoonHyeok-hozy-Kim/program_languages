/* Instead of putting everything in a single file, 
you can use modules to separate codes in separate files as per their functionality. */

import { greetPerson, sum } from "./32_1.js";

console.log(greetPerson('AJ'));
console.log(sum(1, 2));


import { n1, n2 } from "./32_1.js";
console.log(n1());
console.log(n2());

// Rename in the import file
import {
    f1 as x1,
    f2 as x2
} from "./32_1.js"
console.log(x1());
console.log(x2());


// Importing default function
import any_name from "./32_1.js"
console.log(any_name());