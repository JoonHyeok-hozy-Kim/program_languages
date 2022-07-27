#include <stdio.h>
int main() {
	int a;
	a = 127;
	//printf("the value of a in %d-ary is %o. \n", 8, a);
	//printf("the value of a in %d-ary is %d. \n", 10, a);
	//printf("the value of a in %d-ary is %x. \n", 16, a);

	float b = 3.141592f;
	double c = 123.141592;
	printf("In float : %f \n", b);
	printf("In double : %f \n", c);

	printf("b : %.2f \n", b);
	printf("b : %10.10f \n", c);
	printf("a : %5d \n", a);




	return 0;
}