#include <stdio.h>
int sum (int num) {
    static int num_sum = 0;
    num_sum += num;
    return num_sum;
}

int main() {
    printf("%d ",sum(55));
    printf("%d ",sum(45));
    printf("%d ",sum(50));
    return 0;
}