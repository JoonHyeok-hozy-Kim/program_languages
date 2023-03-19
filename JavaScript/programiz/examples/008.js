// Constants are block-scoped
const a = 1;
console.log(a);
{
    const a = 10;
    console.log(a);
}
console.log(a);

// Adding an element to a const array is allowed
const arr = [1,2,3];
console.log(arr)
arr[3] = 'x';
console.log(arr)
// Modifying an element in a const array is allowed