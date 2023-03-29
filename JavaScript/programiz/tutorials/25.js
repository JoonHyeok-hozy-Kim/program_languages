const m1 = []
cnt = 1
for (let i=0; i<3; i++){
    m1.push([]);
    for (let j=0; j<3; j++){
        m1[i].push(cnt++);        
    }
}

for (let i=0; i<3; i++){
    let s = "[";
    for (let j=0; j<3; j++){
        s += m1[i][j];
        s += " ";
    }
    s += "]";
    console.log(s);
}

m1.forEach((row) => {
    let s = "["
    row.forEach((val) => {
        s += val;
        s += " ";        
    })
    s += "]";
    console.log(s);
});

for (let row of m1){
    let s = "["
    for (let val of row){
        s += val;
        s += " ";     
    }
    s += "]";
    console.log(s);
}