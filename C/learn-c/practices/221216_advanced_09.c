#include <stdio.h>
#include <stdlib.h>

union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

typedef struct linked_list{
    char val;
    struct linked_list * prev;
    struct linked_list * next;
} linked_list_t;

linked_list_t * append(linked_list_t * tail, char val){
    if (tail->val == NULL) {
        tail->val = val;
        return tail;
    } else {
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = (linked_list_t *) malloc(sizeof(linked_list_t));
        tail->next->val = val;
        tail->next->prev = tail;
        tail->next->next = NULL;
        return tail->next;
    }
}

void print_hexadecimal(linked_list_t * tail){
    printf("0x");
    while (tail){
        printf("%c", tail->val);
        tail = tail->prev;
    }
}

void get_hexadecimal(int x){
    linked_list_t * tail = (linked_list_t *) malloc(sizeof(linked_list_t));
    tail->val = NULL;
    tail->prev = NULL;
    tail->next = NULL;
    if (x == 0){
        tail = append(tail, '0');
    } else {
        while (x > 0){
            int temp_remainder = x % 16;
            char digit;
            if (temp_remainder < 10) {
                digit = '0' + temp_remainder;
            } else{
                digit = 'a' + (temp_remainder - 10);
            }

            tail = append(tail, digit);

            x /= 16;
        }
    }

    print_hexadecimal(tail);
}

void simple_union_test(){
    union intParts parts;
    parts.theInt = 5968145;

    printf("\nThe int is %i\n", parts.theInt);
    get_hexadecimal(parts.theInt); printf("\n");
    printf("The bytes are [%i %i %i %i]\n", parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);
    get_hexadecimal(parts.bytes[0]); printf(" ");
    get_hexadecimal(parts.bytes[1]); printf(" ");
    get_hexadecimal(parts.bytes[2]); printf(" ");
    get_hexadecimal(parts.bytes[3]); printf(" ");

    int theInt = parts.theInt;
    printf("\nThe int is %i\n", (char*) &theInt);
    printf("The bytes are [%i %i %i %i]\n", ((char*) &theInt)[0], ((char*) &theInt)[1], ((char*) &theInt)[2], ((char*) &theInt)[3]);

}


struct various_nums_explicit{
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    } types;
};

struct various_nums_implicit{
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    };
};

void union_with_various_nums_test(){
    struct various_nums_explicit v1;
    v1.type = 0;
    v1.types.intNum = 1;

    struct various_nums_implicit v2;
    v2.type = 0;
    v2.floatNum = 1.1;
}

union Coins{
    // struct and array shares the same memory!
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    };
    int coins[4];
};

void union_with_identical_data_types(){
    union Coins change;
    
    for (int i=0; i<sizeof(change) / sizeof(int); i++){
        scanf("%i", change.coins + i);
    }

    printf("There are %i quarter,  %i dimes,  %i nickels, and  %i pennies.\n",
        change.quarter, change.dime, change.nickel, change.penny);
}

union IntChars{
    int ints[6];
    char chars[21];
};

int main() {
    // int i;
    // for (i=0; i<255; i++){
    //     printf("\nTarget : %d, Hexa : ", i);
    //     get_hexadecimal(i);
    // }

    // simple_union_test();

    // union_with_various_nums_test();

    // union_with_identical_data_types();

    union IntChars intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};
    /* testing code */
    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for(int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);

}