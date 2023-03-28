function generate_deck(){
    deck = [];
    suits = ["◆", "♤", "♧", "♥"];
    values = ["A", 2,3,4,5,6,7,8,9,"K", "Q", "J"];

    for (let i=0; i<suits.length; i++){
        for (let j=0; j<values.length; j++){
            deck.push(suits[i]+values[j]);
        }
    }

    // console.log(deck);
    return deck;
}

function shuffle_cards(deck, cnt){
    half = Math.floor(deck.length/2);
    for (let i=0; i<cnt; i++){
        console.log("deck " + deck);
        part1 = deck.slice(0, half);
        part2 = deck.slice(half, deck.length);
        // console.log("part1 " + part1);
        // console.log("part2 " + part2);
        i1 = 0;
        i2 = 0;
        new_deck = []
        while (i1 < part1.length || i2 < part2.length){
            if (i2 == part2.length || (i1 < part1.length && Math.random() > 0.5)){
                new_deck.push(part1[i1]);
                i1 += 1;
            } else {
                new_deck.push(part2[i2]);
                i2 += 1;
            }
            // console.log("new_deck " + new_deck);
        }
        deck = new_deck
    }
    return deck
}



deck = generate_deck();
console.log(shuffle_cards(deck, 3));