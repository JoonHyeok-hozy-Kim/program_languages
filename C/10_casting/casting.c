#include <stdio.h>
int main() {

	// What if data type is ignored?
	/*int a;
	double b;
	float f;

	b = 2.4;
	a = b;
	printf("%d", a);
	f = b;
	printf("%f", f);*/

	// data type change : double -> int
	/*int a;
	double b;
	
	b = 2.4;
	a = (int)b;
	printf("%d", a);*/

	// data type change : int -> double
	//int a, b;
	//double c, d;

	//a = 5;
	//b = 3;

	//c = a / b;			// quotient
	//d = (double)a / b;	// division of real numbers
	//printf("%lf %lf", c, d);

	// Q1
	int i;
	float f;

	printf("Input a real number : ");
	scanf("%f", &f);
	i = (int)(f * 100) % 100;
	printf("i = %d\n", i);

	return 0;
}