#include <stdio.h>
#include <string.h>

void stringDeclaration(){
    char * c1 = "abc";
    char c2[] = "abc";
    char c3[4] = "abc";

    printf("c1 : %s, c2 : %s, c3 : %s", c1, c2, c3);
}


void stringRelatedFuncs(){
    char a[] = "Hello";
    char b[] = "World";
    char c[] = "Hello ";

    printf("Length of %s is %d.\n", a, strlen(a));
    
    if (strncmp(a, b, 5) == 0) printf("a = b = %s\n", a);
    if (strncmp(a, c, 5) == 0) printf("a = c = %s\n", a);

    printf("%s\n", strncat(c, b, 5));
    printf("%s\n", strncat(c, a, 4));
}


int main(){
    
    // stringDeclaration();
    stringRelatedFuncs();

    return 0;
}