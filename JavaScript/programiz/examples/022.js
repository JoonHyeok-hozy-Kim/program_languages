function last_digit_check(nums){
    if (nums[0] % 10 != nums[1] % 10){
        return false;
    } else if (nums[0] % 10 != nums[2] % 10){
        return false;
    }
    return true;
}

function run(){
    let nums = [0, 0, 0];
    for (let i=0; i<3; i++){
        nums[i] = parseInt(prompt(`Enter the ${i+1}-th number : `));
    }
    if (last_digit_check(nums)){
        document.write(`${nums[0]}, ${nums[1]} and ${nums[2]} have the same last digit.`);
    } else {
        document.write(`${nums[0]}, ${nums[1]} and ${nums[2]} have different last digit.`);
    }
}

run();