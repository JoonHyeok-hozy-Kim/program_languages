#include <stdio.h>
int main() {
	// Array Introduction
	/*int i;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char crr[3] = { 'a', 'b', 'c' };

	for (i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

	for (i = 0; i < 3; i++) {
		printf("%c\n", crr[i]);
	}*/

	// Allocation of elements after the declaration
	/*int i, sum = 0;
	int arr[3];

	for (i = 0; i < 3; i++) {
		printf("Input Score %d : ", i + 1);
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 3; i++) {
		sum += arr[i];
	}

	printf("Total : %d / Avg : %.2f", sum, (float)sum / 3);*/

	// Prime Number Finder
	/*int i, v=2, n=0, a;
	int arr[1000];

	while (n < 1000) {
		a = 0;
		for (i = 0; i < n; i++) {
			if (v % arr[i] == 0) {
				a = 1;
				break;
			}
		}
		if (a == 0) {
			arr[n] = v;
			++n;
			printf("[%d-th] %d added.\n", n, v);
		}
		++v;
	}*/

	// Concept) Constant
	/*const int a = 3;
	printf("%d", a);*/

	// Initialization of values in an array : 0
	/*int i;
	int arr[4] = { 1 };
	char carr[4] = { 'a' };
	float farr[4] = { 1.1 };

	for (i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}

	for (i = 0; i < 4; i++) {
		printf("%c\n", carr[i]);
	}

	for (i = 0; i < 4; i++) {
		printf("%f\n", farr[i]);
	}*/

	// Q1. Sort the input numbers.
	/*int i, j, v, n = 0;
	int arr[5];

	while (n < 5) {
		printf("Input %d-th number : ", n + 1);
		scanf("%d", &v);

		j = 0;
		for (i = 0; i < n; i++) {
			if (arr[i] < v) {
				j++;
			}
		}
		for (i = n; i > j; i--) {
			arr[i] = arr[i-1];
		}
		arr[j] = v;
		n++;
	}

	printf("{ ");
	for (i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("}");*/

	// Q2. Draw bar chart with input scores
	int i, j, max=0, v, n = 0;
	int arr[5];

	while (n < 5) {
		printf("Input %d-th score : ", n + 1);
		scanf("%d", &v);
		arr[n] = v;
		n++;
		if (max < v) {
			max = v;
		}
	}

	printf("\n<< Score Board>>\n");
	for (i = 0; i < n; i++) {
		printf("[%d-th] ", i+1);
		for (j = 0; j < 20 * arr[i] / max; j++) {
			printf("-");
		}
		printf(" %d \n", arr[i]);
	}

	return 0;
}