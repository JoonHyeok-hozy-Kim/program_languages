// TODO: create the Person class using a function
function Person(name, age){
	this.name = name;
    this.age = age;
    
    this.describe = () => this.name + ", " + this.age + " years old";
}

var jack = new Person("Jack", 25);
var jill = new Person("Jill", 24);
console.log(jack.describe());
console.log(jill.describe());