#include <stdio.h>
int main() {

	int i;
	printf("Input an integer : ");
	scanf("%d", &i);

	// if, else, else if
	/*if (i == 7) {
		printf("Lucky number %d", i);
	}
	else if (i == 6) {
		printf("Great! %d", i);
	}
	else {
		printf("Mediocre %d", i);
	}*/

	// Logical Operations
	if (i > 10 && i <= 20) {
		printf("%d is gt 10 and le to 20", i);
	}
	if (i <= 10 || i > 20) {
		printf("%d is le to 10 or gt 20", i);
	}




	return 0;
}