#include <stdio.h>

void simple_pointer_test(){
    int a = 1;
    int * pointer_to_a = &a;

    printf("a, value : %d\n", a);
    printf("pointer_to_a, value : %d\n", *pointer_to_a);

    printf("\nAddition\n");
    a++;
    printf("a, value : %d\n", a);
    printf("pointer_to_a, value : %d\n", *pointer_to_a);

    printf("\nAddition\n");
    *pointer_to_a += 1;
    printf("a, value : %d\n", a);
    printf("pointer_to_a, value : %d\n", *pointer_to_a);
}


int main() {

    simple_pointer_test();

}