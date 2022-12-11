#include <stdio.h>
int print_hello() {
	printf("Hello! \n");
	return 0;
}

int ret() { return 1000; }

float gain(int input, float i_rate) {
	return (float)input * (1 + i_rate);
}

int magic_box(int n) {
	return n + 4;
}

int summation_from_one(n) {
	int i = 1, sum=0;
	while (i <= n) {
		sum += i;
		i++;
	}
	return sum;
}

int prime_number(n) {
	int i, j, cnt = 0;
	for (i = 2; i <= n; i++) {
		for (j = 2; j <= i; j++) {
			if (j == i) {
			printf("Prime Num : %d\n", i);
			cnt += 1;
			}
			else if (i % j == 0) {
				break;
			}
		}
	}
	return cnt;
}

int factorize(n) {
	int i=2, original=n;
	while (n > 1) {
		if (n % i == 0) {
			printf("%d", i);
			n /= i;
			//printf("\nDEBUG n = %d \n", n);
			if (n == 1) {
				printf(" = %d", original);
			}
			else {
				printf(" X ");
			}
		}
		else {
			i++;
		}
	}
	return 0;
}

int main() {
	/*printf("Call function. \n");
	print_hello();*/



	// Get return value from a function.
	/*int a = ret();
	printf("%d", a);*/



	// Give input to a function and get result.
	//float asset = gain(1000, 0.01);
	//printf("$ %.2f", asset);


	// Q1.
	//printf("%d", magic_box(10));

	// Q3.
	/*printf("%d", summation_from_one(10));*/

	// Q4.
	//printf("Number of Prime numbers : %d", prime_number(10));

	// Q5.
	factorize(240);


	return 0;
}