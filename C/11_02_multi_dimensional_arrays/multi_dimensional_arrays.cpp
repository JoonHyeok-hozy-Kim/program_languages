#include <stdio.h>
int main() {

	// Multidimensional Array Example
	int i, j, cnt=1;
	int arr[4][3];
	int barr[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int carr[][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			arr[i][j] = cnt;
			cnt++;
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%2d ", barr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%2d ", carr[i][j]);
		}
		printf("\n");
	}

	// Q1

}