/* In JavaScript, there are two kinds of object properties:
    1. Data properties
    2. Accessor properties
*/


// 1. Data properties
const student = {
    firstName: "Dan"    // Data properties
};



// 2. Accessor properties
// get - to define a getter method to get the property value
// set - to define a setter method to set the property value
const teacher = {
    firstName: "AJ",

    get getName() {
        return this.firstName;
    },

    set changeName(newName){
        this.firstName = newName;
    }
};
console.log(teacher.firstName);
console.log(teacher.getName);       // This is not a method, so getName() will return error!

teacher.changeName = "Dan";         // How to use setter!
console.log(teacher.getName);




/* Object.defineProperty() */
const parent = {
    firstName: "John"
};

Object.defineProperty(parent, "getName", {
    get : function() {
        return this.firstName;
        }
    }
);

Object.defineProperty(parent, "changeName", {
    set : function(val) {
        this.firstName = val;
        }
    }
);

console.log(parent.getName);
parent.changeName = "Paul";
console.log(parent.getName);