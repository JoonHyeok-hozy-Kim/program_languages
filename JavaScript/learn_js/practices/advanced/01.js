function upperCaseAsync(s) {
    // write your code here
    const p = new Promise((resolve, reject) => {
        resolve(s.toUpperCase());        
    });
        
    return p;
}

upperCaseAsync("steve").then(console.log);
upperCaseAsync(null).catch((x) => {
    console.log("No string received!");
});