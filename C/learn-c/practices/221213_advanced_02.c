#include <stdio.h>

struct point{
    int x, y;
    char * z;
};

typedef struct{
    int x, y;
    char * z;
} new_point;

int main() {

    struct point p1;
    new_point p2;

    p1.x = 1;
    p1.y = 2;
    p1.z = "a";

    p2.x = 3;
    p2.y = 4;
    p2.z = "b";

    return 0;
}