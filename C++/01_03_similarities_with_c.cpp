#include <stdio.h>
#include <iostream>

int variables() {

	int i=0;
	char c='c';
	double d=1.1;
	float f=-2.3f;

	printf("%d\n", i);
	printf("%c\n", c);
	printf("%lf\n", d);
	printf("%f\n", f);

	std::cout << i << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << f << std::endl;

	return 0;
}

void pointers() {

	int i=-1;
	int* pi = &i;
	printf("%d\n", i);
	printf("%d\n", *pi);
	std::cout << i << std::endl;
	std::cout << *pi << std::endl;
	printf("\n");

	int arr[10];
	int* parr = arr;
	for (i = 0; i < 10; i++) {
		arr[i] = i;
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
		std::cout << arr[i] << std::endl;
	}

	printf("\n");

	for (i = 0; i < 10; i++) {
		*parr = 64;
		parr++;
	}

	parr = arr;
	i = 0;
	while (i < 10) {
		printf("%d ", *parr);
		std::cout << *parr << std::endl;
		parr++;
		++i;
	}

	printf("\n");
	for (i = 0; i < 10; i++) {
		std::cout << "(" << arr[i] << ") " << std::endl;
	}


}


void user_input() {

	int user_input, i;
	int arr[10];

	for (i = 0; i < 10; i++) {
		arr[i] = i;
	}

	std::cout << "Guess a number" << std::endl;
	std::cin >> user_input;

	for (i = 0; i < 10; i++) {
		if (arr[i] == user_input) {
			std::cout << user_input << " correct!" << std::endl;
			return;
		}
	}

	std::cout << user_input << " not included." << std::endl;
	return;
}