/**In JavaScript, proxies (proxy object) are used to 
 *   wrap an object and redefine various operations into the object such as reading, insertion, validation, etc. 
 * Proxy allows you to add custom behavior to an object or a function. 
*/


console.log('\n[get handler Example]');
let s1 = {
    age: 28,
    name: 'AJ'
};

const handler1 = {
    // get handler method
    get: function(obj, prop){
        return obj[prop] ? obj[prop] : `Property ${prop} does not exists.`;
    }
}

const proxy1 = new Proxy(s1, handler1);
console.log(proxy1.name);
console.log(proxy1.age);
console.log(proxy1.gender);


console.log('\n[set handler Example]');
const handler2 = {
    // set handler method
    set : function(obj, prop, val){
        obj[prop] = val;
    }
}
const proxy2 = new Proxy(s1, handler2);
s1.gender = 'Female';
console.log(s1.gender);



console.log('\n[Empty Handler]');
const handler3 = { };
const proxy3 = new Proxy(s1, handler3); // identical to s1
console.log(proxy3.name);
console.log(proxy3.age);






/** Applications */
console.log('\n[Application 1. For Validation]');
let s2 = {
    name: 'hozy',
    age: 30
}

const handler_validation = {
    get(obj, prop){
        if (prop == 'name') {
            return obj[prop];
        } else {
            return 'Not Allowed.'
        }
    }
}

const proxy_app1 = new Proxy(s2, handler_validation);
console.log(proxy_app1.name);
console.log(proxy_app1.age);


console.log('\n[Application 2. Read Only View of an Object]');
const handler_read_only = {
    set: function(obj, prop, val) {
        if (obj[prop]){
            console.log('Read only.');
        }
    }
}
const proxy_app2 = new Proxy(s2, handler_read_only);
proxy_app2.name = 'Change';


console.log('\n[Application 3. Side Effects]');
// use a proxy to call another function when a condition is met.
const myFunction = () => console.log('myFunction called.');

const handler_side_effect = {
    set: function(target, prop, value){
        if (prop === 'name' && value === 'AJ'){
            myFunction();
        } else {
            console.log('Write denied.');
        }
    }
}

const proxy_app3 = new Proxy(s2, handler_side_effect);
proxy_app3.name = 'JFK';
proxy_app3.name = 'AJ';