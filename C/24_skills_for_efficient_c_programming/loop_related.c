#include <stdio.h>

void summation_comparison() {

	int i, n = 10, a = 0;

	// Using loop
	for (i = 0; i < n; i++) {
		a += i+1;
	}
	printf("%d\n", a);
	// Using formula instead
	a = n * (n + 1) / 2;
	printf("%d\n", a);

}