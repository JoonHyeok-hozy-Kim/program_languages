#include <stdio.h>
#include <stdlib.h>
#include "struct_dynamic_allocation_test.h"


void struct_array_creation_test() {
	struct Something* somethings;
	int n;

	n = 10;
	somethings = create_something_array(n);
	display_somethings(somethings, n);
}


struct Something* create_something_array(int n) {
	struct Something* arr;
	int i;

	arr = (struct Something*)malloc(sizeof(struct Something) * n);
	for (i = 0; i < n; i++) {
		arr[i].a = i * 10 + 1;
		arr[i].b = i * 10 + 2;
	}
	return arr;
}


void display_somethings(struct Something* arr, int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("[%2d-th] a : %2d, b : %2d\n", i + 1, arr[i].a, arr[i].b);
	}
};

