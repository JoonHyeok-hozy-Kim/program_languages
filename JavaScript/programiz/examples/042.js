function start_end_check_method(S, s, e){
    if (! S.startsWith(s)){
        return false
    } else if (! S.endsWith(e)){
        return false
    }
    return true;
}

function start_end_check(S, s, e){
    if (S[0] != s){
        return false
    } else if (S[S.length-1] != e){
        return false
    }
    return true;
}

a = 'asdb'
console.log(start_end_check_method(a, 'a', 'b'));
console.log(start_end_check_method(a, 'a', 'c'));
console.log(start_end_check_method(a, 'e', 'b'));
console.log(start_end_check_method(a, 'e', 'k'));