const n1 = Math.floor(Math.random() * 10);
const n2 = Math.floor(Math.random() * 10);
const n3 = Math.floor(Math.random() * 10);

console.log(n1, n2, n3);

// Using ternary
if (n1 > n2){    
    console.log(n1 > n3 ? n1 : n3);
} else {
    console.log(n2 > n3 ? n2 : n3);
}


// Using Math.max()
console.log(Math.max(n1, n2, n3));