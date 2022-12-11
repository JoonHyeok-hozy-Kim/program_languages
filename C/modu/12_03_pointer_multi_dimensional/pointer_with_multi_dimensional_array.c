#include <stdio.h>
int main() {

	// Pointer assignment using Array's name.
	/*int arr[3] = { 1,2,3 };
	int* parr;

	parr = arr;

	printf("arr[1] : %d \n", arr[1]);
	printf("parr[1] : %d \n", parr[1]);
	printf("*(parr+1) : %d \n", *(parr+1));

	parr = &arr[0];

	printf("arr[1] : %d \n", arr[1]);
	printf("parr[1] : %d \n", parr[1]);
	printf("*(parr+1) : %d \n", *(parr + 1));*/


	// Iteration Using the pointer
	/*int arr[10];
	int cnt = 1;
	int* parr;

	parr = arr;
	while (parr - arr <= 9) {
		*parr = cnt;
		cnt++;
		parr++;
	}

	parr = arr;
	while (parr - arr <= 9) {
		printf("%d \n", *parr);
		parr++;
	}*/


	// Double Pointer
	/*int a = 1;
	int *pa;
	int **ppa;

	pa = &a;
	ppa = &pa;

	printf("a : %d\n", a);
	printf("*pa : %d\n", *pa);
	printf("*ppa : %p\n", *ppa);
	printf("**ppa : %d\n", **ppa);*/


	// Address of the Array's name
	/*int arr[3] = { 1,2,3 };
	int (*parr)[3] = &arr;

	printf("arr[1] : %d\n", arr[1]);
	printf("*parr[1] : %d\n", (*parr)[1]);

	printf("arr     : %p\n", arr);
	printf("(*parr) : %p\n", (*parr));
	printf("parr    : %p\n", parr);*/


	// Multidimensional Array Searching
	/*int arr[4][3] = { {1,2,3} };
	int *parr = arr;
	int i=1;

	while (parr - arr <= 11) {
		printf("%d", *parr);
		if (i%3 == 0) {
			printf("\n");
		}
		else {
			printf(", ");
		}
		parr++;
		i++;
	}*/

	// 2-Dim pointer
	/*int arr[9][8];
	int(*parr)[8];
	int i, j;

	parr = arr;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 8; j++) {
			arr[i][j] = i * 10 + j;
		}
	}

	for (i = 0; i < 9; i++) {
		printf("%d\n", *parr[0]);
		parr++;
	}*/


	// Pointer Array
	int* arr[3];
	int a = 3, b = 4, c = 5;
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;

	printf("a : %d , *arr[0] : %d \n", a, *arr[0]);
	printf("b : %d , *arr[1] : %d \n", b, *arr[1]);
	printf("c : %d , *arr[2] : %d \n", c, *arr[2]);

	printf("&a : %p , arr[0] : %p", &a, arr[0]);

	return 0;
}