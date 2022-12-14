#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y){
    if (x == 1) return y;
    return multiply(x-1, y);
}

int factorial(int x){
    if (x == 0) return 1;
    if (x == 1 || x == 2) return 2;
    return x * factorial(x-1);
}


int main() {
    printf("%d\n", multiply(3, 4));
    printf("%d\n", factorial(5));
}