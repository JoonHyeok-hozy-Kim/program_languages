#include <stdio.h>
int main() {

	// Pointer Intro
	/*int a;
	a = 2;
	printf("%p \n", &a);
	printf("%x \n", &a);*/

	// Pointer Assignment
	int *p;
	int a;

	p = &a;

	printf("%p \n", p);
	printf("%p \n", &a);
	printf("\n");

	a = 2;

	printf("%p \n", p);
	printf("%p \n", &a);
	printf("\n");

	printf("%d \n", *p);
	printf("%d \n", a);
	printf("\n");

	*p = 3;

	printf("%p \n", p);
	printf("%p \n", &a);
	printf("%d \n", *p);
	printf("%d \n", a);
	printf("\n");

	return 0;
}