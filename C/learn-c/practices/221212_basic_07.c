#include <stdio.h>

int main() {
    int array[10];
    int i;
    for (i=0; i<10; i++) array[i] = i+1;

    int factorial = 1;
    for (i=0; i<10; i++) factorial *= array[i];

    printf("10! is %d.\n", factorial);
}