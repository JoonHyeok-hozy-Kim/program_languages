#include <stdio.h>
int main() {

	// Maximum number of int
	int a = 2147483647;

	printf("%d \n", a);
	printf("%d \n", ++a); // Overflow!

	unsigned int b = 2147483647;

	printf("%u \n", b);
	printf("%u \n", ++b); // No Overflow! unsigned int : [0 ~ 4294967295]

	b = -1;
	printf("%u \n", b);		// Maximum for the unsigned int
	printf("%u \n", ++b);	// Overflow!

	return 0;
}