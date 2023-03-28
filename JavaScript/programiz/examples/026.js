function numSum(num){
    return _numSum(1, num);
};

function _numSum(start, end){
    if (end - start == 0){
        return start;
    } else if (end - start == 1){
        return start + end;
    }

    return start + end + _numSum(start+1, end-1);
};


console.log(numSum(10));