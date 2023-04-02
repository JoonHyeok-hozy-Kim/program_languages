/** Using object literal */
const o1 = {
    p1: 'A',
    p2: 12,
    p3: function() {
        console.log(this.p1);
    },
    p4: {
        pp1: 10,
        pp2: 20
    }
}


/** Create an Object using Instance of Object Directly */
const o2 = new Object( {
    p1: 'A',
    p2: 12,
    p3: function() {
        console.log(this.p1);
    },
    p4: {
        pp1: 10,
        pp2: 20
    }
})


/** Create an object using Constructor Function */
function Ooo() {
    this.p1 = 'A';
    this.p2 = 12;
    this.p3 = function(){
        console.log(this.p1);
    };
    this.p4 = {
        pp1: 10,
        pp2: 20
    };
}
const o3 = new Ooo();