function printFibonacci(num){
    if (num == 0){
        document.write(0);
    } else if (num == 1) {
        document.write(1);
    } else {
        series = [1, 1]
        while (series.length < num){
            series.push(series[series.length-2] + series[series.length-1]);
        }
        for (let x of series){
            document.write(x + " ");
        }
    }
}

const target = parseInt(prompt('Enter the number'));
printFibonacci(target);