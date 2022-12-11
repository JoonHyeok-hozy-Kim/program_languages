#include <stdio.h>
int change_val(int* pi) {

	printf("In function chage_val()\n");
	printf("pi : %p\n", pi);
	printf("*pi : %d\n", *pi);

	*pi = 3;

	printf("In function chage_val()\n");
	printf("pi : %p\n", pi);
	printf("*pi : %d\n", *pi);

	return 0;
}

int swap(int* pi, int* pj) {
	int temp = *pj;

	printf("Swap!\n");
	*pj = *pi;
	*pi = temp;
	printf("*pi : %d, pi : %p\n", *pi, pi);
	printf("*pj : %d, pj : %p\n", *pj, pj);

	return 0;
}

int swap_proto(int* pi, int* pj);

int add_number(int* parr, int len);

int max_array(int* parr, int len);

int add_number_two_dim(int* parr, int row, int col);

int print_two_dim_array(int* parr, int row, int col);

int main() {
	
	// Change main function's variable using pointer
	/*int i = 0;
	printf("In function main()\n");
	printf("&i : %p\n", &i);
	printf("i : %d\n", i);
	printf("\n");
	change_val(&i);
	printf("\n");
	printf("In function main()\n");
	printf("&i : %p\n", &i);
	printf("i : %d\n", i);*/


	// Swap variable using pointer function
	/*int i=3, j=4;

	printf("i : %d, &i : %p\n", i, &i);
	printf("j : %d, &j : %p\n", j, &j);

	swap(&i, &j);

	printf("i : %d, &i : %p\n", i, &i);
	printf("j : %d, &j : %p\n", j, &j);*/


	// Using prototype for function.
	/*int i=3, j=4;

	printf("i : %d, &i : %p\n", i, &i);
	printf("j : %d, &j : %p\n", j, &j);

	swap_proto(&i, &j);

	printf("i : %d, &i : %p\n", i, &i);
	printf("j : %d, &j : %p\n", j, &j);*/


	// Function input : Array
	/*int arr[3] = { 1,2,3 };
	int i;

	printf("Before add_number \n");
	for (i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	add_number(arr, 3);


	printf("After add_number \n");
	for (i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}*/


	// Q1.
	/*int arr[5] = { 1,2,7,4,5 };
	printf("%d", max_array(arr, 5));*/


	// Q2.
	int arr[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };

	print_two_dim_array(arr, 4, 3);
	add_number_two_dim(arr, 4, 3);
	print_two_dim_array(arr, 4, 3);


	return 0;
}


int swap_proto(int* pi, int* pj) {
	int temp = *pj;

	printf("Swap PROTOTYPE!\n");
	*pj = *pi;
	*pi = temp;
	printf("*pi : %d, pi : %p\n", *pi, pi);
	printf("*pj : %d, pj : %p\n", *pj, pj);

	return 0;
}

int add_number(int* parr, int len) {
	int i;
	
	for (i = 0; i < len; i++) {
		*parr += 1;
		parr += 1;
	}

	return 0;
}


int max_array(int* parr, int len) {
	int i, temp = *parr;

	parr++;
	for (i = 1; i < len; i++) {
		if (*parr > temp) {
			temp = *parr;
		}
		parr++;
	}

	return temp;
}

int add_number_two_dim(int* parr, int row, int col) {
	int i, temp;
	for (i = 0; i < row * col; i++) {
		temp = *parr;
		temp++;
		*parr = temp;
		parr++;
	}
	printf("add_number_two_dim() finished. \n");

	return 0;
};

int print_two_dim_array(int* parr, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", *parr);
			parr++;
		}
		printf("\n");
	}
	

	return 0;
};