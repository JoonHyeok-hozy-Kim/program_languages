function guessNumber(upper_bound){
    const target = Math.floor(Math.random() * upper_bound);
    let guess = -1;

    while (target !== guess){
        guess = parseInt(prompt(`Make a guess between 0 to ${upper_bound} (Answer : ${target})`));
    }

    alert('Congrats!');
}

guessNumber(100);