console.log("\n[Basic example]")
const nums = [1,2,3,4];
for (let n of nums){
    console.log(n);
}

console.log("\n[String example]")
const str1 = "abcde";
for (let c of str1){
    console.log(c);
}

console.log("\n[set example]")
const set1 = new Set([1,2,3]);
for (let i of set1){
    console.log(i);
}

console.log("\n[map example]")
const map1 = new Map();
for (let i=0; i<10; i++){
    map1.set(i, String.fromCharCode(i+65));
}
for (let [k, v] of map1){
    console.log(`${k} : ${v}`);
}

console.log("\n[User Defined Iterator example]")
const customIterableObj = {
    // iterator method
    [Symbol.iterator]() {
        let step = 0;
        return {
            next() {
                step++;
                if (step === 1){
                    return { value: '1', done: false };
                } else if (step === 2){
                    return { value: '2', done: false };
                } else if (step === 3){
                    return { value: '3', done: false };
                }
                return { value: '', done: true };
            }
        }
    }
}
for (const ci of customIterableObj){
    console.log(ci);
}


console.log("\n[Generator example]")
function* fibonacci(N) {
    let cnt = 0;
    let p1 = 1;
    let p2 = 1;

    while (cnt < N){
        cnt++;
        // console.log(`cnt : ${cnt}`);
        if (cnt==1){
            yield 1;
        } else if (cnt==2){
            yield 1;
        } else {
            let temp = p1;
            p1 = p2;
            p2 += temp;
            yield p2;
        }
    }
}

const fiboObj = fibonacci(10);

for (let v of fiboObj){
    console.log(v);
}