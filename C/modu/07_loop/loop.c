#include <stdio.h>
int main() {

	// for loop syntax
	/*int i;
	for (i = 0; i < 20; i++) {
		printf("%d \n", i);
	}

	for (i = 0; i < 20; ++i) {
		printf("%d \n", i);
	}*/

	// Average Score
	/*int i;
	int subject, score;
	double sum_score = 0;

	printf("How many subjects will you input? : ");
	scanf("%d", &subject);

	for (i = 0; i < subject; i++) {
		printf("Input %d-th score : ", i+1);
		scanf("%d", &score);
		sum_score += score;
	}

	printf("Average score is %.2lf", sum_score / subject);*/

	// Endless loop syntax
	/*int num;

	for (;;) {
		printf("Guess integer to escape : ");
		scanf("%d", &num);
		if (num == 3) {
			break;
		}
		else {
			printf("Wrong. \n");
		}
	}*/

	// 9X9
	/*int i, j;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			printf("%d X %d = %d \n", i, j, i * j);
		}
	}*/

	// while loop
	/*int i = 0, sum = 0;
	while (i < 10) {
		i++;
		sum += i;
		printf("%d \n", sum);
	}*/

	// do ~ while syntax
	/*int i = 1, sum = 0;
	do {
		sum += i;
		i++;
		printf("%d \n", sum);
	} while (i < 10);*/

	// Star Increasing
	/*int i, j, n;	

	printf("Number of Lines : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			printf(" ");
		}
		for (j = 0; j < i*2 + 1; j++) {
			printf("*");
		}
		printf("\n");
	}*/

	// Star Decreasing
	/*int i, j, n;

	printf("Number of Lines : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = 0; j < (n-i)*2-1; j++) {
			printf("*");
		}
		printf("\n");
	}*/

	// Q3.
	/*int i=1, sum=0;
	while (i <= 1000) {
		if (i % 3 == 0 || i % 5 == 0) {
			printf("%d\n", i);
			sum += i;
		}
		i++;
	}
	printf("%d", sum);*/

	// Q4.
	/*int i = 0, j = 1, k, sum=0;
	while (j <= 1000000) {
		printf("%d\n", j);
		if (j % 2 == 0) {
			sum += j;
		}
		k = j;
		j += i;
		i = k;
	}
	printf("sum : %d\n", sum);*/

	//Q5.
	/*int i=1, num, perm=1;
	printf("Input N : ");
	scanf("%d", &num);

	while (i <= num) {
		perm *= i;
		i++;
	}
	printf("%d\n", perm);*/
	
	// Q6
	/*int a, b, c, cnt=0;
	for (a = 1; a <= 2000/3; a++) {
		for (b = a + 1; b <= (2000-a)/2; b++) {
			c = 2000 - a - b;
			if (b < c) {
				printf("%d %d %d\n", a, b, c);
				cnt++;
			}
		}
	}
	printf("%d", cnt);*/

	// Q7
	int i = 2, j, num;

	printf("Input integer : ");
	scanf("%d", &num);

	while ((i + 1) * (i + 1) <= num) {
		i++;
	}
	printf("%d = ", num);
	for (j = 2; j <= i; j++) {
		while (num % j == 0) {
			printf("%d", j);
			num /= j;
			if (num > 1) {
				printf(" X ");
			}
		}		
	}
	if (num > i) {
		printf("%d", num);
	}

	return 0;
}