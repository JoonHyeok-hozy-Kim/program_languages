#include <stdio.h>
#include <stdlib.h>

void someFunction(int arg){
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

void function_pointer_simple_test(){
    void (*pointer_for_function)(int);
    pointer_for_function = &someFunction;
    printf("We're about to call someFunction() using a pointer!\n");
    (pointer_for_function)(5);
    printf("Wow that was cool. Back to main now!\n\n");
}

int compare(const void* left, const void* right){
    return (*(int*)right - *(int*)left);
}

void qsort_example(){
    int (*cmp)(const void* left, const void* right);
    cmp = &compare;

    int arr[] = {1,2,3,4,5,6,7,8,9};

    qsort(arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), cmp); // Argumetns : _Base, _NumOfElements, _SizeOfElements, _CompareFunction
    int i;
    for (i=0; i<sizeof(arr)/sizeof(*arr); i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    // function_pointer_simple_test();

    qsort_example();
}