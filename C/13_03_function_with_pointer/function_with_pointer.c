#include <stdio.h>
int pswap(int** ppa, int** ppb);
int add_one_to_elements(int(*arr)[2], int row);
int read_val(const int val);
int max(int a, int b);

// Q1.
int ranker();
int sort(int* arr, int len);

// Q2.
int euclidean(int *arr, int len);

// Q3.
int recursive_factorial(int n);

// Q4.
int convert_numeral_system(int n, int prev_base, int new_base);
int numeral_encoder(int n, int base);
int numeral_decoder(int n, int base);
int power(int base, int exponent);

int main() {

	// Swapping Pointers
	/*int a = 3, b = 4;
	int* pa, * pb;

	pa = &a;
	pb = &b;

	printf("Address of pa             : %p\n", &pa);
	printf("Address pa is pointing at : %p\n", pa);
	printf("Value assigned at pa      : %d\n", *pa);
	printf("\n");
	printf("Address of pb             : %p\n", &pb);
	printf("Address pb is pointing at : %p\n", pb);
	printf("Value assigned at pb      : %d\n", *pb);

	pswap(&pa, &pb);

	printf("Address of pa             : %p\n", &pa);
	printf("Address pa is pointing at : %p\n", pa);
	printf("Value assigned at pa      : %d\n", *pa);
	printf("\n");
	printf("Address of pb             : %p\n", &pb);
	printf("Address pb is pointing at : %p\n", pb);
	printf("Value assigned at pb      : %d\n", *pb);*/


	// Two Dimensional Array Function-Input 
	/*int arr[3][2];
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			arr[i][j] = (i + 1) * 10 + j + 1;
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	add_one_to_elements(arr, 3);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/


	// Pointer of a Function.
	/*int a, b;
	int (*pmax)(int, int);
	pmax = max;

	a = 5;
	b = 6;
	printf("max(a,b) = %d\n", max(a, b));
	printf("pmax(a,b) = %d\n", pmax(a, b));*/

	
	// Q1.
	//ranker();

	// Q2.
	/*int arr[3] = { 66, 44, 121 };
	printf("%d", euclidean(arr, 3));*/

	// Q3.
	//printf("Recursive Factorial : %d", recursive_factorial(6));

	// Q4.
	//convert_numeral_system(111, 3, 4);

	// Q5
	sieve_of_eratosthenes(10);

	return 0;
}

int pswap(int** ppa, int** ppb) {
	int* temp = *ppa;

	*ppa = *ppb;
	*ppb = temp;

	printf("====================\nPointer Swapped!\n====================\n");

	return 0;
}


int add_one_to_elements(int(*arr)[2], int row) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < 2; j++) {
			arr[i][j] ++;
		}
	}


	return 0;
}


int read_val(const int val) {

	// Wrong!!! Cannot change the value of a constant input.
	// val = 12;

	return 0;
};

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
};


//Q1
int ranker() {
	int temp, sum, total_sum=0;
	int arr[5];
	int i;

	for (i = 0; i < 5; i++) {
		sum = 0;
		printf("%d-th Student's math score : ", i+1);
		scanf("%d", &temp);
		sum += temp;
		printf("%d-th Student's Korean score : ", i + 1);
		scanf("%d", &temp);
		sum += temp;
		printf("%d-th Student's English score : ", i + 1);
		scanf("%d", &temp);
		sum += temp;

		arr[i] = sum / 3;
		total_sum += sum;
	}

	total_sum /= 15;

	sort(arr, 5);

	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
		if (arr[i] > total_sum) {
			printf("Passed.\n");
		}
		else {
			printf("Failed\n");
		}
	}

	return 0;
}

int sort(int* arr, int len) {
	int i, j, temp;

	for (i = 1; i < len; i++) {
		j = i;
		temp = arr[j];
		while (j > 0) {
			if (arr[j - 1] > temp) {
				arr[j] = arr[j - 1];
				j--;
			}
			else {
				break;
			}
		}
		arr[j] = temp;
	}

	return 0;
};

// Q2.
int euclidean(int* arr, int len) {
	int num1=*(arr), num2;
	int i;

	int mod, temp;
	
	for (i = 1; i < len; i++) {
		arr++;
		num2 = *(arr);

		mod = 2;
		while (mod > 0) {
			if (num2 > num1) {
				temp = num1;
				num1 = num2;
				num2 = temp;
			}

			mod = num1 % num2;
			if (mod == 0) {
				num1 = num2;
			}
			else {
				num1 %= num2;
			}
		}
	}

	return num1;
};

// Q3.
int recursive_factorial(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * recursive_factorial(n - 1);
	}	
};

// Q4.
int convert_numeral_system(int n, int prev_base, int new_base) {
	int prev_num, new_num;

	printf("%d (%d)\n", n, prev_base);
	prev_num = numeral_decoder(n, prev_base);
	printf("%d (10)\n", prev_num);
	new_num = numeral_encoder(prev_num, new_base);
	printf("%d (%d)\n", new_num, new_base);
	return new_num;

};

int numeral_encoder(int n, int base) {
	int digit = 0, result = 0;
	int remainder;
	while (n > 0) {
		remainder = n % base;
		result += remainder * power(10, digit);
		n /= base;
		digit++;
	}
	return result;
}

int numeral_decoder(int n, int base) {
	int digit = 0, result=0;
	int unit;
	while (n >= 10) {
		unit = n % 10;
		result += unit * power(base, digit);
		n /= 10;
		digit++;
	}
	result += n * power(base, digit);
	return result;
};

int power(int base, int exponent) {
	int result = 1, i;
	for (i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}
