#include <stdio.h>
#include "function_related.h"

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

__inline int imax(int a, int b) {
	if (a > b) return a;
	return b;
}


void func_compare() {
	int a = 4, b = 5;
	printf("max(%d, %d) = %d\n", a, b, max(a, b));
	printf("imax(%d, %d) = %d\n", a, b, imax(a, b));
}