#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct linked_list {
    int val;
    struct linked_list * prev;
    struct linked_list * next;
} linked_list_t;

void print_binary_for_int(int x){
    if (x == 0) {
        printf("0");
    } else {
        linked_list_t * l = (linked_list_t *) malloc(sizeof(linked_list_t));
        l->prev = NULL;
        l->next = NULL;
        while (x > 0){
            l->val = x % 2;
            x /= 2;
            if (x==0) break;
            l->next = (linked_list_t *) malloc(sizeof(linked_list_t));
            l->next->prev = l;
            l->next->next = NULL;
            l->next->val = NULL;
            l = l->next;
        }

        while (l){
            if (l->next) free(l->next);
            printf("%d", l->val);
            l = l->prev;
        }
    }
}

void print_binary_for_char(char c){
    int i;
    for (i=7; i>=0; i--){
        if (c & (1<<i)){
            printf("1");
        } else {
            printf("0");
        }
    }
}

void bit_n_setting_test(){
    char storage = 0;
    int i;
    for (i=0; i<8; i++){
        storage |= 1 << i;  // Set!

        print_binary_for_char(storage);
        printf("\n");
    }
}

void bit_n_clearing_test() {
    char storage = 255;
    int i;
    
    for (i=0; i<8; i++){
        storage &= ~(1 << i);  // Clear!

        print_binary_for_char(storage);
        printf("\n");
    }
}

void bit_n_flipping_test(){
    char storage = 133;
    printf("Initial : ");
    print_binary_for_char(storage);

    int i;
    for (i=0; i<8; i++){
        storage ^= 1<<i;
    }
    
    printf("\nAfter Flip : ");
    print_binary_for_char(storage);
    printf("\n");
}


const short FLAG_ON          = 1 << 0; // 1  (0x01)
const short FLAG_MOVEMENT    = 1 << 1; // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04)
const short FLAG_ALIVE       = 1 << 3;
const short FLAG_BROKEN      = 1 << 4;
const short FLAG_EDIBLE      = 1 << 5; // 32 (0x20)

void learn_c_question(){
  short attributes = 0;

  /* Set the attributes ON, TRANSPARENT, and BROKEN */
  attributes |= (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN);
  assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));

  /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
  attributes &= ~(FLAG_TRANSPARENT | FLAG_BROKEN);
  attributes |= FLAG_ALIVE;
  assert(attributes == (FLAG_ON | FLAG_ALIVE));

  /* Check if the ALIVE flag is set */
  assert(attributes & FLAG_ALIVE);

  /* Check if the BROKEN flag is not set */
  assert(attributes & ~(FLAG_BROKEN));

  /* Modify so only the EDIBLE attribute is set */
  attributes = 0;
  attributes |= FLAG_EDIBLE;
  assert(attributes == FLAG_EDIBLE);

  printf("Done!");

}

int main() {

    // int i;
    // for(i=0; i<10; i++) {
    //     printf("print_binary for %d : ", i);
    //     print_binary_for_int(i);
    //     printf("\n");
    // }
    
    // bit_n_setting_test();
    // bit_n_clearing_test();
    // bit_n_flipping_test();

    learn_c_question();

}