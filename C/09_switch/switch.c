#include <stdio.h>
int main() {
	// Switch example
	int i;
	printf("Pet simulator.\n");
	printf("1. Feed.\n");
	printf("2. Wash.\n");
	printf("3. Sleep.\n");
	printf("Do : ");
	scanf("%d", &i);

	switch (i) {
	case 1:
		printf("Yum!");
		break;
	case 2:
		printf("No!");
		break;
	case 3:
		printf("zzz");
		break;
	default:
		printf("???");
		break;
	}


	return 0;
}