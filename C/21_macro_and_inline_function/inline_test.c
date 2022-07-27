#include <stdio.h>

__inline int square(int a) { return a * a; }

void inline_square_test() {

	printf("%d\n", square(3));
	printf("%d\n", square(3 + 1)); // Not like macro, (3+1)*(3+1) operated.

}

__inline int inline_max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


void inline_max_test() {

	int a = 3;
	int b = 4;

	printf("%d\n", inline_max(a, b));

}