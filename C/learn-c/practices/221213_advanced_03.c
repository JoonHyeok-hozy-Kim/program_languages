#include <stdio.h>

void add_one_test1(int x){
    printf("add_one_test1\n");
    x += 1;
}

void add_one_test2(int * x){
    printf("add_one_test2\n");
    (*x) += 1;
}

void dereference_test(){
    printf("[dereference_test]\n");
    int n = 1;
    printf("n : %d\n", n);

    add_one_test1(n);
    printf("n : %d\n", n);

    add_one_test2(&n);
    printf("n : %d\n", n);
}

typedef struct{
    int x;
    int y;
} point;

void move_one_type1(point * p){
    printf("move_one_type1\n");
    (*p).x++;
    (*p).y++;
}

void move_one_type2(point * p){
    printf("move_one_type2\n");
    p->x++;
    p->y++;
}

void function_with_struct_test(){
    printf("\n[function_with_struct_test]\n");
    point p1;
    p1.x = 1;
    p1.y = 1;

    printf("point : (%d,%d)\n", p1.x, p1.y);

    move_one_type1(&p1);
    printf("point : (%d,%d)\n", p1.x, p1.y);
    move_one_type2(&p1);
    printf("point : (%d,%d)\n", p1.x, p1.y);
}

int main(){
    dereference_test();
    function_with_struct_test();
}