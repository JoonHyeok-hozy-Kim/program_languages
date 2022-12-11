#include <stdio.h>
#include <stdlib.h>
#include "dynamic_alloc.h"

void dynamic_array_creation_test() {
	int* da1;
	int n, i;

	for (n = 1; n < 10; n++) {
		da1 = create_int_dynamic_array_with_malloc(n);
		for (i = 0; i < n; i++) {
			da1[i] = i + 1;
		}

		for (i = 0; i < n; i++) {
			printf("%d ", da1[i]);
		}
		printf("\n");
	}

	free(da1); // freeing heap memory that we used for malloc.

}

int* create_int_dynamic_array_with_malloc(int size) {
	int* arr;
	arr = (int*)malloc(sizeof(int) * size);
	return arr;
}


void two_dim_dynamic_array_using_pointer_array_test() {
	int** td;
	int i, j, k;
	int row, col;

	row = 4;
	col = 3;

	td = create_two_dim_array_with_pointer_array(row, col);

	// Alocate values
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			td[i][j] = i * 10 + j;
		}
	}

	// Display Matrix
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%2d ", td[i][j]);
		}
		printf("\n");
	}

	// Free memories.
	for (i = 0; i < row; i++) {
		free(td[i]);
	}
	free(td);


}

int** create_two_dim_array_with_pointer_array(int row, int col) {
	int** arr;
	int i;

	arr = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		arr[i] = (int*)malloc(sizeof(int) * col);
	}
	return arr;
}


void two_dim_dynamic_array_using_array_pointer_test() {
	int** td;
	int i, j;
	int row, col;

	row = 4;
	col = 3;
	td = create_two_dim_array_with_array_pointer(4, 3);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			td[i][j] = i;
		}
	}

}


int** create_two_dim_array_with_array_pointer(int row, int col) {
	//int(*arr)[col] = (int(*)[col])malloc(row * col * sizeof(int));
}