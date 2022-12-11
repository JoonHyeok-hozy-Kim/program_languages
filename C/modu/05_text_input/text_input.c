#include <stdio.h>
int main() {
	// Simple Input Test
	char a;
	a = 'A';
	//printf("value : %d, char %c", a, a);


	// Celsius - Farenheit conversion example.
	double celsius;
	//printf("Change celsius into Farenheit. \n");
	//printf("Input degrees in celsius : ");
	//scanf("%lf", &celsius);
	//printf("%.2f celsius is equal to %.2f Farenheit. \n", celsius, 9 * celsius / 5 + 32);
	

	// Various data type input
	char ch;
	short sh;
	int i;
	long lo;
	float fl;
	double du;

	printf("Input char : ");
	scanf("%c", &ch);

	printf("Input short : ");
	scanf("%hd", &sh);

	printf("Input int : ");
	scanf("%d", &i);

	printf("Input long : ");
	scanf("%ld", &lo);

	printf("Input float : ");
	scanf("%f", &fl);

	printf("Input double : ");
	scanf("%lf", &du);

	printf("char : %c, short : %hd, int : %d, ", ch, sh, i);
	printf("long : %ld, float : %f, double : %lf \n", lo, fl, du);

	return 0;
}