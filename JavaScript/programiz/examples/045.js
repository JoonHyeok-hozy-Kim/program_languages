const student = { 
    name: 'John',
    age: 20,
    hobbies: ['reading', 'games', 'coding'],
};


console.log('\n[for ... in]')
for (let key in student){
    console.log(`${key} : ${student[key]}`);
}


console.log('\n[for ... of]')
for (let [k, v] of Object.entries(student)){
    console.log(`${k} : ${v}`);
}