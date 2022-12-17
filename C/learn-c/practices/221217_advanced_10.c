#include <stdio.h>

int pointer_increment_test(){
    int int_array[5] = {10,20,30,40,50};
    int i;

    printf("Iteration Case\n");
    for (i=0; i<5; i++){
        printf("int_array[%d] = %d, at address : %x\n", i, int_array[i], &int_array[i]);
    }

    printf("\nPointer Increment Case\n");
    int * int_pointer = &int_array[0];
    for (i=0; i<5; i++){
        printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
        int_pointer++;
    }

    printf("\nPointer Decrement Case\n");
    int_pointer = &int_array[4];
    for (i=0; i<5; i++){
        printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
        int_pointer--;
    }
    
    printf("\nPointer Addition/Subtraction with integers\n");
    int_pointer = &int_array[0];
    printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
    int_pointer += 2;
    printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
    int_pointer -= 2;
    printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
    int_pointer += 4;
    printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
    int_pointer -= 1;
    printf("int_pointer = %d, at address : %x\n", *int_pointer, int_pointer);
}


int main() {

    pointer_increment_test();


}