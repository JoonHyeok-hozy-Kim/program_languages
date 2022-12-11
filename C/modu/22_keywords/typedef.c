#include "typedef.h"

void typedef_test() {
	Human Adam = { 31, 171, 69, 0 };
	Human Eve = { 28, 160, 51, 0 };

	print_status(Adam);
	print_status(Eve);
};

int print_status(Human human) {
	if (human.gender == 0) {
		printf("MALE\n");
	}
	else {
		printf("FEMALE\n");
	}

	printf("Age : %d / Height : %d / Weight : %d\n", human.age, human.height, human.weight);

};


void calculator_simulation() {

	CAL_TYPE input;
	CAL_TYPE a, b;

	while (1) {
		printf("\n<Calculator>\n");
		printf("1. Addition\n");
		printf("2. Deduction\n");
		printf("3. Exit\n");
		scanf("%d", &input);

		if (input == 3) {
			break;
		}
		else {
			printf("Number1 : ");
			scanf("%d", &a);
			printf("Number2 : ");
			scanf("%d", &b);
			if (input == 1) {
				printf("Result : %d + %d = %d\n", a, b, a + b);
			}
			else {
				printf("Result : %d - %d = %d\n", a, b, a - b);
			}
		}
	}
}



int add(int a, int b) { return a + b; };
typedef int NUM_TYPE;
typedef int (*Padd)(int, int);
typedef int Arrays[10];
void various_typedef_test() {

	NUM_TYPE a = 10;
	Arrays arr = { 1,2,3 };
	Padd prr = add;
	printf("a : %d\n", a);
	printf("arr[2] : %d\n", arr[2]);
	printf("prr(3,5) : %d\n", prr(3,5));
}