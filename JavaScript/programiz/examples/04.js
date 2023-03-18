// Example 1: Area When Base and Height is Known
let base = 8;
let height = 12;
let area_base_height = (base * height) / 2;
console.log(`Area1 : ${area_base_height}`);


// Example 2: Area When All Sides are Known
let a = 10, b = 10, c = 12;
let s = (a+b+c) / 2;
let area_sides = Math.sqrt(s * (s-a) * (s-b) * (s-c));
console.log(`Area2 : ${area_sides}`);